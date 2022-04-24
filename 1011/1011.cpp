#include <stdio.h>

int main() {
  float max_profit = 0;
  int flag = 0;
  char eng[] = {'W', 'T', 'L'};
  float odd_max[3] = {0};

  for (int i = 0; i < 3; i++) {
    int max = 0;
    for (int j = 0; j < 3; j++) {
      float temp = 0;
      scanf("%f", &temp);
      if (temp > odd_max[i]) {
        odd_max[i] = temp;
        max = j;
      }
    }
    if (flag++) putchar(' ');
    printf("%c", eng[max]);
  }
  max_profit = (odd_max[0] * odd_max[1] * odd_max[2] * 0.65 - 1) * 2;
  printf(" %.2f", max_profit);
  return 0;
}