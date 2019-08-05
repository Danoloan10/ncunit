#include "ncunit.h"
#include <setjmp.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void execute_test(char * (*test)(), void (*before)(), void (*after)(), char * name) {
	if(before != NULL) (*before)();

	char * result = (*test)();
	print_header(name);
	if (result == NULL) {
		print_ok(name);
	} else {
		print_error(name, result);
	}

	if(after != NULL) (*after)();
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

	uint8_t * c_actual = (uint8_t *) actual;
	uint8_t * c_expect = (uint8_t *) expected;
	
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

	uint8_t * u = malloc(n);

	int segv;
	if(!(segv = setjmp(env)))
		memcpy(u, ptr, n);
	free(u);

	sigaction(SIGSEGV, &oact, NULL);
	
	if(segv) {
		return 0;
	}else{
		return 1;
	}
}

int not_equals_float(float actual, float expected, float epsilon){
	if(equals_float(actual, expected, epsilon))
		return 0;
	else return 1;
}
int not_equals_double(double actual, double expected, double epsilon){
	if(equals_double(actual, expected, epsilon))
		return 0;
	else return 1;
}

int not_equals_ptr(void * actual, void * expected, size_t n_bytes){
	if(equals_ptr(actual, expected, n_bytes))
		return 0;
	else return 1;
}

int not_mem_access(void * ptr, size_t n){
	if(mem_access(ptr, n))
		return 0;
	else return 1;
}
