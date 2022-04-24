#include <stdio.h>

int main() {
  int sum_[2][3] = {0};
  char c;
  for (int i = 0, flag = 0, id = 0; (c = getchar()) != '\n'; i++) {
    if (c == ' ') {
      flag = 1;
      id = 0;
      continue;
    }
    if (c == '.')
      id++;
    else
      sum_[flag][id] = (c - '0') + sum_[flag][id] * 10;
  }

  printf("%d.%d.%d",
         ((sum_[0][2] + sum_[1][2]) / 29 + sum_[0][1] + sum_[1][1]) / 17 +
             sum_[0][0] + sum_[1][0],
         ((sum_[0][2] + sum_[1][2]) / 29 + sum_[0][1] + sum_[1][1]) % 17,
         (sum_[0][2] + sum_[1][2]) % 29);

  return 0;
}