#include "nunit.h"
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

jmp_buf env;
void sigsegv(int sig) {
	longjmp(env, 1);
}

void print_error(const char * test, const char * msg, va_list ap) {
	printf("[nunit] XX %s: ERROR: ", test);
	vprintf(msg, ap);
	printf("\n");
}

void print_ok(const char * test) {
	printf("[nunit] $$ %s: OK\n", test);
}

int assert_true(int boolean, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(!boolean){
		print_error(test, msg, ap);	
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_equals_int(int actual, int expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(actual != expected){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_equals_char(char actual, char expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(actual != expected){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_equals_short(short actual, short expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(actual != expected){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_equals_long(long actual, long expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(actual != expected){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_equals_long_long(long long actual, long long expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(actual != expected){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}

int assert_equals_float(float actual, float expected, float epsilon, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(epsilon < 0) epsilon = -epsilon;
	
	if(actual > expected + epsilon || actual < expected - epsilon){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_equals_double(double actual, double expected, double epsilon, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(epsilon < 0) epsilon = -epsilon;
	
	if(actual > expected + epsilon || actual < expected - epsilon){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}

int assert_equals_str(char * actual, char * expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(strcmp(actual, expected)){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_equals_ptr(void * actual, void * expected, size_t n_bytes, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	int i;

	char * c_actual = (char *) actual;
	char * c_expect = (char *) expected;
	
	for(i = 0; i < n_bytes; i++){
		if(c_actual[i] != c_expect[i]){
			print_error(test, msg, ap);
			return -1;
		}
	}

	print_ok(test);
	return 0;
}
int assert_equals_obj(void * actual, void * expected, int (* comp)(void *, void*), const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if((*comp)(actual, expected)){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}

int assert_mem_access(void * ptr, size_t n, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	struct sigaction act;
	act.sa_handler = sigsegv;
	act.sa_flags = 0;
	sigaction(SIGSEGV, &act, NULL);

	int segv;
	for(int i = 0; (i < n) && !(segv = setjmp(env)); i++) {
		uint8_t u = *(((uint8_t*) ptr) + i);
	}
	
	if(segv) {
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}

int assert_false(int boolean, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(boolean){
		print_error(test, msg, ap);	
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_not_equals_int(int actual, int expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(actual == expected){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_not_equals_char(char actual, char expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(actual == expected){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_not_equals_short(short actual, short expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(actual == expected){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_not_equals_long(long actual, long expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(actual == expected){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_not_equals_long_long(long long actual, long long expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(actual == expected){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}

int assert_not_equals_float(float actual, float expected, float epsilon, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(epsilon < 0) epsilon = -epsilon;
	
	if(actual <= expected + epsilon && actual >= expected - epsilon){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_not_equals_double(double actual, double expected, double epsilon, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(epsilon < 0) epsilon = -epsilon;
	
	if(actual <= expected + epsilon && actual >= expected - epsilon){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}

int assert_not_equals_str(char * actual, char * expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(!strcmp(actual, expected)){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
int assert_not_equals_ptr(void * actual, void * expected, size_t n_bytes, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	int i;

	char * c_actual = (char *) actual;
	char * c_expect = (char *) expected;
	
	for(i = 0; i < n_bytes; i++){
		if(c_actual[i] == c_expect[i]){
			print_error(test, msg, ap);
			return -1;
		}
	}

	print_ok(test);
	return 0;
}
int assert_not_equals_obj(void * actual, void * expected, int (* comp)(void *, void*), const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	if(!(*comp)(actual, expected)){
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}

int assert_not_mem_access(void * ptr, size_t n, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	struct sigaction act;
	act.sa_handler = sigsegv;
	act.sa_flags = 0;
	sigaction(SIGSEGV, &act, NULL);

	int segv;
	for(int i = 0; (i < n) && !(segv = setjmp(env)); i++) {
		uint8_t u = *(((uint8_t*) ptr) + i);
	}
	
	if(!segv) {
		print_error(test, msg, ap);
		return -1;
	}else{
		print_ok(test);
		return 0;
	}
}
