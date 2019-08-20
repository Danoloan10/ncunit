libncunit.a: ncunit.o
	ar rc $@ ncunit.o
clean:
	rm ncunit.o libncunit.a
install: libncunit.a ncunit.h
	cp libncunit.a /usr/lib/
	cp ncunit.h /usr/include/

uninstall:
	rm /usr/lib/libncunit.a
	rm /usr/include/ncunit.h
