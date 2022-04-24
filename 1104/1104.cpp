#include <cstdio>

int main() {
  int num;
  double in, out = 0;
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    scanf("%lf", &in);
    out += in * (num - i) * (i + 1);
  }
  printf("%.02f", out);
  return 0;
}