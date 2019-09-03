libncunit.a: ncunit.o
	ar rc $@ ncunit.o
clean:
	rm ncunit.o libncunit.a
	rm example/test/*
	touch example/test/dummy
install: libncunit.a ncunit.h
	cp libncunit.a /usr/lib/
	cp ncunit.h /usr/include/

uninstall:
	rm /usr/lib/libncunit.a
	rm /usr/include/ncunit.h

example: libncunit.a example/src/example.c
	gcc -o example/test/example example/src/example.c -I. -L. -lncunit
	
