#include <stdio.h>

int main() {
  int cost = 0, from = 0, to = 0;
  int num;
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    scanf("%d", &to);
    if (to > from)
      cost += ((to - from) * 6 + 5);
    else
      cost += ((from - to) * 4 + 5);
    from = to;
  }
  printf("%d", cost);
  return 0;
}