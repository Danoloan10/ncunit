#include "../../ncunit.h"

int sum (int a, int b) {
	return a + b;
}

const char * ok () {
	int a = 2, b = 1;
	int expected = 3;
	int obtained = sum(a, b);
	assert((obtained == expected), "obtained: %d, expected: %d", obtained, expected);
	return NULL;
}

const char * nok () {
	int a = 2, b = -1;
	int expected = 3;
	int obtained = sum(a, b);
	assert((obtained == expected), "obtained: %d, expected: %d", obtained, expected);
	/*
	 * Returning a string without assert may give an error
	 * 
	 */
return "error";
}

int main(void) {
	execute_test(ok, NULL, NULL, "ok");
	execute_test(nok, NULL, NULL, "nok");
	return 0;
}
