#include <stdio.h>
#include <string.h>

int output(char* str, int n1, int n2, int n3, int n);

int main() {
  char str[100] = {0};
  int n = 0, n1 = 0, n2 = 0, n3 = 0;
  scanf("%s", str);
  n = strlen(str);
  n2 = (n + 2) / 3 + (n + 2) % 3;
  n1 = n3 = (n + 2) / 3;
  output(str, n1, n2, n3, n);
  return 0;
}

int output(char* str, int n1, int n2, int n3, int n) {
  for (int i = 0; i < n1; i++) {
    if (i < n1 - 1) {
      putchar(str[i]);
      for (int j = 0; j < n2 - 2; j++) putchar(' ');
      putchar(str[n - i - 1]);
      putchar('\n');
    } else {
      while (i < n - n1 + 1) {
        putchar(str[i++]);
      }
    }
  }
  return 0;
}