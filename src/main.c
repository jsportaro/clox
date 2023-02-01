#include <stdio.h>
#include <stdlib.h>

#include <clox.h>

int main(int argc, char *argv[]) {

  if (argc == 1) {
    repl();
  } else if (argc == 2) {
    runFile(argv[1]);
  } else {
    fprintf(stderr, "Usage: clox [path]\n");
    exit(64);
  }

  return EXIT_SUCCESS;
}
