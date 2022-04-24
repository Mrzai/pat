#include <stdio.h>

int main() {
  int sum, i, j;
  scanf("%d", &i);
  scanf("%d", &j);
  sum = i + j;
  if (sum < 0) {
    printf("-");
    sum = -sum;
  }
  if (sum >= 1000000) {
    printf("%d,", sum / 1000000);
    printf("%03d,", (sum / 1000) % 1000);
    printf("%03d", sum % 1000);
  } else if (sum >= 1000) {
    printf("%d,", sum / 1000);
    printf("%03d", sum % 1000);
  } else
    printf("%d", sum);
  return 0;
}