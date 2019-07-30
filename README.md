**ncunit**

Minimal (nano) C unit testing library.

This library allows to compare all the primitive types and print formatted messages based on the results.
It also includes generic assertions of random memory, both byte-by-byte comparison (see `assert_equals_ptr`) and using a custom comparison function (see `assert_equals_obj`); and assertion of access to memory (see `assert_mem_access`).

You could have written this library. Now you don't have to.

For documentation, see the header file `ncunit.h`
