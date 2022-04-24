#include <stdio.h>

int main() {
  int flag = 0;
  int sum = 0;
  char c;
  while ((c = getchar()) != '\n') {
    sum += c - '0';
  }
  char n2e[][7] = {"zero", "one", "two",   "three", "four",
                   "five", "six", "seven", "eight", "nine"};
  if (sum / 100) {
    if (flag++) putchar(' ');
    printf("%s", n2e[sum / 100]);
  }
  if (sum % 100 / 10 || sum / 100) {
    if (flag++) putchar(' ');
    printf("%s", n2e[sum % 100 / 10]);
  }
  if (flag++) putchar(' ');
  printf("%s", n2e[sum % 10]);
  return 0;
}