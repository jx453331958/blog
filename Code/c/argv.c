#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  int ret = toupper(argv[1][0]);
  printf("%d \n", argc);
  printf("%d", ret);
}