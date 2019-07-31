**ncunit**

Minimal (nano) C unit testing library.

This library defines a model to implement unit tests, as well as some utility functions that can be useful when doing so, like byte-by-byte comparisons of random memory (see `assert_equals_ptr`) and assertion of access to memory (see `assert_mem_access`).

A test is defined as a function of the form:
```
char * test();
```
This function shall return NULL if the test has been passed successfully, or a string representing the error message otherwise.

Inside tests, assertions may be included. Assertions are of the form:
```
assert(int cond, char * msg, ...);
```
where «cond» is the condition to check (the assertion will fail iff cond == 0), and «msg, ...» is the formatted message (printf style) to show when the assertion fails.
Assertions may only be used inside tests, not anywhere in the code.

To execute a test, simply call the function `execute_test`:
```
execute_test(char * (*test)(), char * name);
```
where «name» is the name of the test to be executed.

The results of the different tests will be shown through STDERR.

-

To install:
```
sudo make install
```
To uninstall:
```
sudo make uninstall
```
If anything fails, first try to clean and recompile, then reinstall:
```
make clean; make
sudo make install
```

You could have written this library. Now you don't have to.

For documentation, see the header file `ncunit.h`
