#include <stdio.h>

int IsPalindromic(int *str, int &len, int num, int radix) {
  while (num != 0) {
    str[len++] = num % radix;
    num /= radix;
  }
  int j = len - 1;
  for (int i = 0; i < j; i++, j--) {
    if (str[i] != str[j]) return 0;
  }
  return 1;
}

int main() {
  int str[100];
  int input_num = 0, input_radix = 0, len = 0, flag = 0;
  scanf("%d%d", &input_num, &input_radix);
  printf("%s",
         IsPalindromic(str, len, input_num, input_radix) ? "Yes\n" : "No\n");
  for (int i = len - 1; i >= 0; i--) {
    if (flag++) putchar(' ');
    printf("%d", str[i]);
  }
  return 0;
}
