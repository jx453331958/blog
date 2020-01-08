#include <stdio.h>
#include <string.h>

int main()
{
  char s[] = "666";
  char s2[] = {'6', '6', '6', '\0'};
  int length = strlen(s);
  int length2 = strlen(s2);
  printf("%d\n", length);
  printf("%d", length2);
}