ncunit
======
Minimal (nano) C unit testing library.

This library defines a model to implement unit tests, as well as some helper functions that might be useful when doing so, like byte-by-byte comparisons of random memory (see `equals_ptr`) and check of access to memory (see `mem_access`).

You could have written this library. Now you don't have to.

For further documentation, including the helper functions defined in the library, see the header file `ncunit.h`

Usage
-----
A test is defined as a function of the form:
```
char * test();
```
This function can be named whatever, and must return NULL if the test has been passed successfully. Assertions may be used to make the test fail given the desired circumstances.

Inside tests, assertions may be included. Assertions are of the form:
```
assert(int cond, char * msg, ...);
```
where «cond» is the condition to check (the assertion will fail iff cond == 0), and «msg, ...» is the formatted message (printf style) to show when the assertion fails.
Assertions make the test they are in return the error message when the condition is false.
Because of this, assertions may only be used inside tests, not anywhere in the code.

To execute a test, simply call the function `execute_test`:
```
execute_test(char * (*test)(), void (*before)(), void (*after)(), char * name);
```
where «test» is the function representing the test, «name» is the name of the test to be executed,
«before» is a function to be run before the test and «after» a function to be run after the test
(if any of these two last arguments is NULL, they will be ignored)

The results of the different tests will be shown through STDERR as follows:
```
[nunit] >> Test: test_1
[nunit] $$ test_1: OK
[nunit] >> Test: test_2
[nunit] XX test_2: ERROR: Sample error message
...
```

This output makes it easy to automate the tests using simple shell scripts.
The script `example_script` is an example of automation that runs all the tests in `./test/` and exits with 0 if there have been no errors or 1 otherwise - this way, it is easily usable inside `make`.

Installation
-----------
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
