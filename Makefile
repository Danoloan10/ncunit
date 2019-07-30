libncunit.a: ncunit.o
	ar rc $@ ncunit.o
ncunit.o: ncunit.c
	gcc -c ncunit.c -o ncunit.o -Wall
clean:
	rm ncunit.o libncunit.a
install: libncunit.a ncunit.h
	cp libncunit.a /usr/lib/
	cp ncunit.h /usr/include/

uninstall:
	rm /usr/lib/libncunit.a
	rm /usr/include/ncunit.h
