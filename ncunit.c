#include "ncunit.h"
#include <setjmp.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>

static jmp_buf env;
static void sigsegv(int sig) {
	longjmp(env, 1);
}

static void print_header(const char * test) {
	fprintf(stderr, "[nunit] >> Test: %s", test);
	fprintf(stderr, "\n");
}

static void print_error(const char * test, const char * msg) {
	fprintf(stderr, "[nunit] XX %s: ERROR: ", test);
	fprintf(stderr, msg);
	fprintf(stderr, "\n");
}

static void print_ok(const char * test) {
	fprintf(stderr, "[nunit] $$ %s: OK\n", test);
}

void execute_test(char * (*test)(), char * name) {
	char * result = (*test)();
	print_header(name);
	if (result == NULL) {
		print_ok(name);
	} else {
		print_error(name, result);
	}
}

int equals_float(float actual, float expected, float epsilon){
	if(epsilon < 0) epsilon = -epsilon;
	return actual <= expected + epsilon && actual >= expected - epsilon;
}
int equals_double(double actual, double expected, double epsilon){
	if(epsilon < 0) epsilon = -epsilon;
	return actual <= expected + epsilon && actual >= expected - epsilon;
}

int equals_ptr(void * actual, void * expected, size_t n_bytes) {
	int i;

	char * c_actual = (char *) actual;
	char * c_expect = (char *) expected;
	
	for(i = 0; i < n_bytes; i++){
		if(c_actual[i] != c_expect[i]){
			return 0;
		}
	}

	return 1;
}

int mem_access(void * ptr, size_t n){
	struct sigaction act;
	struct sigaction oact;
	act.sa_handler = sigsegv;
	act.sa_flags = 0;
	sigaction(SIGSEGV, &act, &oact);

	int segv;
	for(int i = 0; (i < n) && !(segv = setjmp(env)); i++) {
		uint8_t u = *(((uint8_t*) ptr) + i);
	}

	sigaction(SIGSEGV, &oact, NULL);
	
	if(segv) {
		return 0;
	}else{
		return 1;
	}
}

int not_equals_float(float actual, float expected, float epsilon){
	if(epsilon < 0) epsilon = -epsilon;
	return actual > expected + epsilon || actual < expected - epsilon;
}
int not_equals_double(double actual, double expected, double epsilon){
	if(epsilon < 0) epsilon = -epsilon;
 	return actual > expected + epsilon || actual < expected - epsilon;
}

int not_equals_ptr(void * actual, void * expected, size_t n_bytes){
	int i;

	char * c_actual = (char *) actual;
	char * c_expect = (char *) expected;
	
	for(i = 0; i < n_bytes; i++){
		if(c_actual[i] == c_expect[i]){
			return 0;
		}
	}

	return 1;
}

int not_mem_access(void * ptr, size_t n){
	struct sigaction act;
	struct sigaction oact;
	act.sa_handler = sigsegv;
	act.sa_flags = 0;
	sigaction(SIGSEGV, &act, &oact);

	int segv;
	for(int i = 0; (i < n) && !(segv = setjmp(env)); i++) {
		uint8_t u = *(((uint8_t*) ptr) + i);
	}

	sigaction(SIGSEGV, &oact, NULL);
	
	if(!segv) {
		return 0;
	}else{
		return 1;
	}
}
