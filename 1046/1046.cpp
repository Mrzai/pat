#include <stdio.h>
#define maxsize 100001

int main() {
  int dis[maxsize] = {0};
  int n = 0, m = 0, sum = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int temp;
    scanf("%d", &temp);
    sum += temp;
    dis[i] = sum;
  }
  scanf("%d", &m);
  while (m--) {
    int left, right, out = 0;
    scanf("%d%d", &left, &right);
    if (left > right) {
      int temp = left;
      left = right;
      right = temp;
    }
    out = dis[right - 1] - dis[left - 1];
    printf("%d\n", out < sum - out ? out : sum - out);
  }
  return 0;
}