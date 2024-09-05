CC = clang
CFLAGS = -I. -Wall -Wextra -g
DEPS = common.h

clox: clox.o chunk.o memory.o debug.o value.o vm.o compiler.o scanner.o

.PHONY: clean
clean:
	rm -f *.o clox