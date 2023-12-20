/**
 * Author(s):
 * Date:
 *
 * This is a series of exercises to introduce loop
 * control structures.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if(argc != 2) {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    exit(1);
  }

  int n = atoi(argv[1]);

  // A simple for loop that prints 0 thru 9
  for(int i=0; i<10; i++) {
    printf("%d\n", i);
  }

  //1. Rewrite the given for loop as an equivalent while loop
  int j = 10;
  while (j < 20) {
    printf("%d ", j);
    j += 3;
  }
  printf("\n");

  //2. Rewrite the given while loop as an equivalent for loop
  for(int k = 3; k > -4; k--) {
    printf("%d ", k);
  }
  printf("\n");

  //3. Print numbers 1 thru n separated by a comma except for
  //   the last one; example: 1, 2, 3, 4, 5
  for (int i = 1; i <= n; i++) {
    printf("%d", i);
    if (i < n) {
      printf(", ");
    }
  }
  printf("\n");

  //4. Print squares of numbers 1 thru n separated by a comma
  //   except for the last one; example: 1, 4, 9, 16, 25
  for (int i = 1; i <= n; i++) {
    printf("%d", i * i);
    if (i < n) {
      printf(", ");
    }
  }
  printf("\n");

  //5. Compute the summation of numbers 1 thru n and print
  //   the result; example: 1 + 2 + 3 + 4 + 5 = 15
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  printf("Sum of numbers 1 to %d = %d\n", n, sum);

  //6. Compute the summation of squares of numbers 1 thru n
  //   and print the result; example: 1^2 + 2^2 + 3^2 + 4^2 + 5^2 = 55
  int sumOfSquares = 0;
  for (int i = 1; i <= n; i++) {
    sumOfSquares += i * i;
  }
  printf("Sum of squares of numbers 1 to %d = %d\n", n, sumOfSquares);

  //7. Compute the summation of even numbers 1 thru n and print
  //   the result; example (n=5): 2 + 4 = 6
  int sumOfEvens = 0;
  for (int i = 2; i <= n; i += 2) {
    sumOfEvens += i;
  }
  printf("Sum of even numbers 1 to %d = %d\n", n, sumOfEvens);

  //8. Write a solution to the following variation of the FizzBuzz
  //   problem.  Print out integers 1 thru n, one to a line, except
  //   that if the integer is divisible by 7 print "Foo" instead.
  //   If the integer is divisible by 11 print "Bar" instead.  If
  //   the integer is divisible by both 7 and 11, print "FooBar"
  //   instead.
  for (int i = 1; i <= n; i++) {
    if (i % 7 == 0 && i % 11 == 0) {
      printf("FooBar\n");
    } else if (i % 7 == 0) {
      printf("Foo\n");
    } else if (i % 11 == 0) {
      printf("Bar\n");
    } else {
      printf("%d\n", i);
    }
  }

  return 0;
}
