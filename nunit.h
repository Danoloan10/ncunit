#ifndef NUNIT
#define NUNIT

#include <stddef.h>

/* This function compares the two integers <<actual>> and <<expected>>
 * 	If they are equal, the function returns 0
 * 	If they are not equal, the formatted message <<msh, ...>>
 * 		is printed and -1 is returned
 */
int assert_equals_int(int actual, int expected, const char * test, const char * msg, ...);
/* This function compares the two characters <<actual>> and <<expected>>
 * 	If they are equal, the function returns 0
 * 	If they are not equal, the formatted message <<msh, ...>>
 * 		is printed and -1 is returned
 */
int assert_equals_char(char actual, char expected, const char * test, const char * msg, ...);
/* This function compares the two short <<actual>> and <<expected>>
 * 	If they are equal, the function returns 0
 * 	If they are not equal, the formatted message <<msh, ...>>
 * 		is printed and -1 is returned
 */
int assert_equals_short(short actual, short expected, const char * test, const char * msg, ...);
/* This function compares the two long <<actual>> and <<expected>>
 * 	If they are equal, the function returns 0
 * 	If they are not equal, the formatted message <<msh, ...>>
 * 		is printed and -1 is returned
 */
int assert_equals_long(long actual, long expected, const char * test, const char * msg, ...);
/* This function compares the two long long <<actual>> and <<expected>>
 * 	If they are equal, the function returns 0
 * 	If they are not equal, the formatted message <<msh, ...>>
 * 		is printed and -1 is returned
 */
int assert_equals_long_long(long long actual, long long expected, const char * test, const char * msg, ...);

/* This function compares the two float <<actual>> and <<expected>>
 * with an accuracy of <<epsilon>>
 * 	If they are equal, the function returns 0
 * 	If they are not equal, the formatted message <<msh, ...>>
 * 		is printed and -1 is returned
 */
int assert_equals_float(float actual, float expected, float epsilon, const char * test, const char * msg, ...);
/* This function compares the two double <<actual>> and <<expected>>
 * with an accuracy of <<epsilon>>
 * 	If they are equal, the function returns 0
 * 	If they are not equal, the formatted message <<msh, ...>>
 * 		is printed and -1 is returned
 */
int assert_equals_double(double actual, double expected, double epsilon, const char * test, const char * msg, ...);

/* This function compares the two strings <<actual>> and <<expected>>
 * with an accuracy of <<epsilon>>
 * 	If they are equal, the function returns 0
 * 	If they are not equal, the formatted message <<msh, ...>>
 * 		is printed and -1 is returned
 */
int assert_equals_str(char * actual, char * expected, const char * test, const char * msg, ...);
/* This function compares byte by byte the memory pointed by <<actual>> and <<expected>>
 * up to a total number of <<n_bytes>> bytes
 * 	If all of the <<n_bytes>> bytes are equal, the function returns 0
 * 	If not all of the <<n_bytes>> are not equal, the formatted message <<msh, ...>>
 * 		is printed and -1 is returned
 */
int assert_equals_ptr(void * actual, void * expected, size_t n_bytes, const char * test, const char * msg, ...);
/* This function compares two objects passed as raw memory <<actual>> and <<expected>>,
 * using a function <<comp(void *, void *)>> passed as parameter.
 * The function <<comp(void *, void *)>> should return 0 if both of the objects passed as parameters
 * are equal, and other value otherwise
 * 	If the arguments are equal, the function returns 0
 * 	If they are not equal, the formatted message <<msh, ...>>
 * 		is printed and -1 is returned
 */
int assert_equals_obj(void * actual, void * expected, int (* comp) (void *, void *), const char * test, const char * msg, ...);

/*
 * From here below all the functions are the negated logic versions of the above
 */

int assert_not_equals_int(int actual, int expected, const char * test, const char * msg, ...);
int assert_not_equals_char(char actual, char expected, const char * test, const char * msg, ...);
int assert_not_equals_short(short actual, short expected, const char * test, const char * msg, ...);
int assert_not_equals_long(long actual, long expected, const char * test, const char * msg, ...);
int assert_not_equals_long_long(long long actual, long long expected, const char * test, const char * msg, ...);

int assert_not_equals_float(float actual, float expected, float epsilon, const char * test, const char * msg, ...);
int assert_not_equals_double(double actual, double expected, double epsilon, const char * test, const char * msg, ...);

int assert_not_equals_str(char * actual, char * expected, const char * test, const char * msg, ...);
int assert_not_equals_ptr(void * actual, void * expected, size_t n_bytes, const char * test, const char * msg, ...);
int assert_not_equals_obj(void * actual, void * expected, int (* comp) (void *, void *), const char * test, const char * msg, ...);

#endif
