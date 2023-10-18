#include <stdio.h>

int main() {

  float area, base, height;

  printf("Please enter the base of a triangle: ");

  scanf("%f", &base);

  printf("Please enter the height of a triangle: ");

  scanf("%f", &height);

  area = 1/2 * base * height;

  printf("The area is %f square units.\n", area);

  return 0;
}