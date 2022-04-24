#include <stdio.h>

int main() {
  int in[3];
  char output[14] = {"0123456789ABC"};
  scanf("%d%d%d", in, in + 1, in + 2);
  putchar('#');
  for (int i = 0; i < 3; i++) {
    if (in[i] / 13)
      printf("%c", output[in[i] / 13]);
    else
      putchar('0');
    putchar(output[in[i] % 13]);
  }
}