CC = clang
CFLAGS = -I. -Wall -Wextra
DEPS = common.h

clox: clox.o chunk.o memory.o debug.o

.PHONY: clean
clean:
	rm -f *.o clox