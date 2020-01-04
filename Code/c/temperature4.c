#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
  int fahr = LOWER;
  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    printf("%d, %.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }
}