#ifndef NUNIT
#define NUNIT

#include <stddef.h>
#include <stdio.h>

/*
 * This macro defines an assertion.
 * Assertions are only to be used inside of tests (see execute_test)
 */
#define assert(cond, ...) { \
	if(!cond) { \
		int __size = snprintf(NULL, 0, __VA_ARGS__); \
		char * __msg = malloc(__size + 1); \
		sprintf(__msg, __VA_ARGS__); \
		return __msg; \
	} \
}

/*
 * This function executes a test. A test is a function of the form:
 * 	(char *) test()
 * This test function shall return NULL when successful, and a string representing
 * the error message otherwise. It is recommended to user the macro 'assert' before defined.
 * <<name>> is the name of the test run, used for output.
 */
void execute_test(char * (*test)(), void (*before)(), void (*after)(), char * name);

/* Below there are declarations of several helper functions,
 * that can be used to complement assertions.
 */

/* This function compares the two float <<actual>> and <<expected>>
 * with an accuracy of <<epsilon>>
 * 	If they are equal, the function returns 1
 * 	If they are not equal, 0 is returned
 */
int equals_float(float actual, float expected, float epsilon);
/* This function compares the two double <<actual>> and <<expected>>
 * with an accuracy of <<epsilon>>
 * 	If they are equal, the function returns 1
 * 	If they are not equal, 0 is returned
 */
int equals_double(double actual, double expected, double epsilon);

/* This function compares byte by byte the memory pointed by <<actual>> and <<expected>>
 * up to a total number of <<n_bytes>> bytes
 * 	If all of the <<n_bytes>> bytes are equal, the function returns 1
 * 	If not all of the <<n_bytes>> are not equal, 0 is returned
 */
int equals_ptr(void * actual, void * expected, size_t n_bytes);

/* This function checks whether the <<n>> bytes of memory starting at <<ptr>> can be accessed
 * without a segment violation.
 *      If said memory can be accessed, it returns 1
 * 	If SIGSEGV is received, 0 is returned
 */
int mem_access(void * ptr, size_t n);

/*
 * From here below all the functions are the negated logic versions of the above
 */

int not_equals_float(float actual, float expected, float epsilon);
int not_equals_double(double actual, double expected, double epsilon);

int not_equals_ptr(void * actual, void * expected, size_t n_bytes);

int not_mem_access(void * ptr, size_t n);

#endif
