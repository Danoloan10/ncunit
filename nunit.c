#include "nunit.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

int assert_equals_int(int actual, int expected, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(actual != expected){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}
int assert_equals_char(char actual, char expected, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(actual != expected){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}
int assert_equals_short(short actual, short expected, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(actual != expected){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}
int assert_equals_long(long actual, long expected, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(actual != expected){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}
int assert_equals_long_long(long long actual, long long expected, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(actual != expected){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}

int assert_equals_float(float actual, float expected, float epsilon, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(epsilon < 0) epsilon = -epsilon;
	
	if(actual > expected + epsilon || actual < expected - epsilon){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}
int assert_equals_double(double actual, double expected, double epsilon, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(epsilon < 0) epsilon = -epsilon;
	
	if(actual > expected + epsilon || actual < expected - epsilon){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}

int assert_equals_str(char * actual, char * expected, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(strcmp(actual, expected)){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}
int assert_equals_ptr(void * actual, void * expected, size_t n_bytes, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	int i;
	
	char * c_actual = (char *) actual;
	char * c_expect = (char *) expected;
	
	for(i = 0; i < n_bytes; i++){
		if(c_actual[i] != c_expect[i]){
			vprintf(msg, ap);
			return -1;
		}
	}

	return 0;
}
int assert_equals_obj(void * actual, void * expected, int (* comp)(void *, void*), const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if((*comp)(actual, expected)){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}

	return 0;
}

int assert_not_equals_int(int actual, int expected, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(actual == expected){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}
int assert_not_equals_char(char actual, char expected, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(actual == expected){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}
int assert_not_equals_short(short actual, short expected, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(actual == expected){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}
int assert_not_equals_long(long actual, long expected, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(actual == expected){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}
int assert_not_equals_long_long(long long actual, long long expected, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(actual == expected){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}

int assert_not_equals_float(float actual, float expected, float epsilon, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(epsilon < 0) epsilon = -epsilon;
	
	if(actual <= expected + epsilon && actual >= expected - epsilon){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}
int assert_not_equals_double(double actual, double expected, double epsilon, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(epsilon < 0) epsilon = -epsilon;
	
	if(actual <= expected + epsilon && actual >= expected - epsilon){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}

int assert_not_equals_str(char * actual, char * expected, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(!strcmp(actual, expected)){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}
}
int assert_not_equals_ptr(void * actual, void * expected, size_t n_bytes, const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	int i;
	
	char * c_actual = (char *) actual;
	char * c_expect = (char *) expected;
	
	for(i = 0; i < n_bytes; i++){
		if(c_actual[i] == c_expect[i]){
			vprintf(msg, ap);
			return -1;
		}
	}

	return 0;
}
int assert_not_equals_obj(void * actual, void * expected, int (* comp)(void *, void*), const char * msg, ...){
	va_list ap;
	va_start(ap, msg);
	
	if(!(*comp)(actual, expected)){
		vprintf(msg, ap);
		return -1;
	}else{
		return 0;
	}

	return 0;
}
