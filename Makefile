CC = clang
CFLAGS = -I.
DEPS = common.h

clox: clox.o

.PHONY: clean
clean:
	rm -f *.o