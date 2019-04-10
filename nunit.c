#include "nunit.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

int assert_equals_int(int actual, int expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(actual != expected){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}
int assert_equals_char(char actual, char expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(actual != expected){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}
int assert_equals_short(short actual, short expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(actual != expected){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}
int assert_equals_long(long actual, long expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(actual != expected){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}
int assert_equals_long_long(long long actual, long long expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(actual != expected){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}

int assert_equals_float(float actual, float expected, float epsilon, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(epsilon < 0) epsilon = -epsilon;
	
	if(actual > expected + epsilon || actual < expected - epsilon){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}
int assert_equals_double(double actual, double expected, double epsilon, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(epsilon < 0) epsilon = -epsilon;
	
	if(actual > expected + epsilon || actual < expected - epsilon){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}

int assert_equals_str(char * actual, char * expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(strcmp(actual, expected)){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}
int assert_equals_ptr(void * actual, void * expected, size_t n_bytes, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	int i;

	printf("[nunit] >> Testing: %s\n", test);
	
	char * c_actual = (char *) actual;
	char * c_expect = (char *) expected;
	
	for(i = 0; i < n_bytes; i++){
		if(c_actual[i] != c_expect[i]){
			printf("[nunit] >> >> %s: ERROR: ", test);
			vprintf(msg, ap);
			printf("\n");
			return -1;
		}
	}

	printf("[nunit] >> >> %s: OK\n", test);
	return 0;
}
int assert_equals_obj(void * actual, void * expected, int (* comp)(void *, void*), const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if((*comp)(actual, expected)){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}

	printf("[nunit] >> >> %s: OK\n", test);
	return 0;
}

int assert_not_equals_int(int actual, int expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(actual == expected){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}
int assert_not_equals_char(char actual, char expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(actual == expected){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}
int assert_not_equals_short(short actual, short expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(actual == expected){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}
int assert_not_equals_long(long actual, long expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(actual == expected){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}
int assert_not_equals_long_long(long long actual, long long expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(actual == expected){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}

int assert_not_equals_float(float actual, float expected, float epsilon, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(epsilon < 0) epsilon = -epsilon;
	
	if(actual <= expected + epsilon && actual >= expected - epsilon){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}
int assert_not_equals_double(double actual, double expected, double epsilon, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(epsilon < 0) epsilon = -epsilon;
	
	if(actual <= expected + epsilon && actual >= expected - epsilon){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}

int assert_not_equals_str(char * actual, char * expected, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(!strcmp(actual, expected)){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}
}
int assert_not_equals_ptr(void * actual, void * expected, size_t n_bytes, const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	int i;

	printf("[nunit] >> Testing: %s\n", test);
	
	char * c_actual = (char *) actual;
	char * c_expect = (char *) expected;
	
	for(i = 0; i < n_bytes; i++){
		if(c_actual[i] == c_expect[i]){
			printf("[nunit] >> >> %s: ERROR: ", test);
			vprintf(msg, ap);
			printf("\n");
			return -1;
		}
	}

	printf("[nunit] >> >> %s: OK\n", test);
	return 0;
}
int assert_not_equals_obj(void * actual, void * expected, int (* comp)(void *, void*), const char * test, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);

	printf("[nunit] >> Testing: %s\n", test);
	
	if(!(*comp)(actual, expected)){
		printf("[nunit] >> >> %s: ERROR: ", test);
		vprintf(msg, ap);
		printf("\n");
		return -1;
	}else{
		printf("[nunit] >> >> %s: OK\n", test);
		return 0;
	}

	printf("[nunit] >> >> %s: OK\n", test);
	return 0;
}
