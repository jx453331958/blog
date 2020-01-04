#include <stdio.h>

main()
{
  int fahr = 0;
  for (fahr; fahr <= 300; fahr += 20) {
    printf("%d, %.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }
}