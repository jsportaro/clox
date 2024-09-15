CC = clang
CFLAGS = -I. -Wall -Wextra -g3
DEPS = common.h

.PHONY: clean

clox: clox.o chunk.o debug.o value.o vm.o compiler.o memory.o scanner.o object.o table.o

clean:
	rm -f *.o clox