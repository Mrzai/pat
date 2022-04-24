#include <stdio.h>

int main() {
  int m = 0, times = 0, n = 0, max = -1;
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n * m; i++) {
    int temp;
    scanf("%d", &temp);
    if (temp != max) {
      times--;
      if (times < 1) {
        max = temp;
        times = 1;
      }
    } else
      times++;
  }
  printf("%d", max);
}