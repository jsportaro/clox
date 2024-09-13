CC = clang
CFLAGS = -I. -Wall -Wextra -g
DEPS = common.h

clox: clox.o chunk.o debug.o value.o vm.o compiler.o memory.o scanner.o object.o table.o

.PHONY: clean
clean:
	rm -f *.o clox