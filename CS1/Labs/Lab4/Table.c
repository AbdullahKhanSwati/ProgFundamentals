#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  if(argc != 2) {
    printf("Error: provide an integer\n");
    exit(1);
  }

  int n = atoi(argv[1]);
  if(n <= 0) {
    printf("empty table!\n");
    exit(0);
  }

  // Generating and printing the multiplication table
  printf("Multiplication Table for %d:\n", n);
  for(int i = 1; i <= 10; i++) {
    printf("%d x %d = %d\n", n, i, n * i);
  }

  return 0;
}
