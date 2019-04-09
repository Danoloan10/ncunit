libnunit.a: nunit.o
	ar rc $@ nunit.o
nunit.o: nunit.c
	gcc -c nunit.c -o nunit.o -Wall
clean:
	rm nunit.o libnunit.a
install: libnunit.a nunit.h
	cp libnunit.a /usr/lib/
	cp nunit.h /usr/include/
