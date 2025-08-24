#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}
// (1. A)
// int main (void) {
//   int i = 10000;
//   dump(&i, sizeof(i));
//   return 0;
// }
// (1. B)
// int main (void) {
//   long i = 10000;
//   dump(&i, sizeof(i));
//   return 0;
// }
// (1. C)
// int main (void) {
//   short i = 10000;
//   dump(&i, sizeof(i));
//   return 0;
// }
// (1. D)
// int main (void) {
//   char i = 'a';
//   dump(&i, sizeof(i));
//   return 0;
// }
// (1. E)

int main (void) {
  char p[] = "A \n$";
  dump(p, sizeof(p));
  return 0;
}