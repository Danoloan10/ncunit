#ifndef NUNIT
#define NUNIT

#include <stddef.h>

int assert_equals_int(int actual, int expected, const char * msg, ...);
int assert_equals_char(char actual, char expected, const char * msg, ...);
int assert_equals_short(short actual, short expected, const char * msg, ...);
int assert_equals_long(long actual, long expected, const char * msg, ...);
int assert_equals_long_long(long long actual, long long expected, const char * msg, ...);

int assert_equals_float(float actual, float expected, float epsilon, const char * msg, ...);
int assert_equals_double(double actual, double expected, double epsilon, const char * msg, ...);

int assert_equals_str(char * actual, char * expected, const char * msg, ...);
int assert_equals_ptr(void * actual, void * expected, size_t n_bytes, const char * msg, ...);
int assert_equals_obj(void * actual, void * expected, int (* comp) (void *, void *), const char * msg, ...);

int assert_not_equals_int(int actual, int expected, const char * msg, ...);
int assert_not_equals_char(char actual, char expected, const char * msg, ...);
int assert_not_equals_short(short actual, short expected, const char * msg, ...);
int assert_not_equals_long(long actual, long expected, const char * msg, ...);
int assert_not_equals_long_long(long long actual, long long expected, const char * msg, ...);

int assert_not_equals_float(float actual, float expected, float epsilon, const char * msg, ...);
int assert_not_equals_double(double actual, double expected, double epsilon, const char * msg, ...);

int assert_not_equals_str(char * actual, char * expected, const char * msg, ...);
int assert_not_equals_ptr(void * actual, void * expected, size_t n_bytes, const char * msg, ...);
int assert_not_equals_obj(void * actual, void * expected, int (* comp) (void *, void *), const char * msg, ...);

#endif
