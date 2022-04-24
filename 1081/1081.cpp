#include <stdio.h>

int main() {
  long long int in[2] = {0}, out[2] = {0, 1};
  int num;
  scanf("%d", &num);
  while (num--) {
    scanf("%lld/%lld", in, in + 1);
    out[0] = in[0] * out[1] + in[1] * out[0];
    out[1] = in[1] * out[1];
    int M = out[1] < out[1] ? out[1] : out[1];
    for (int i = 2; i <= M; i++) {
      if (out[0] % i == 0 && out[1] % i == 0) {
        out[0] /= i;
        out[1] /= i;
        M /= i;
        i--;
      }
    }
  }
  if (out[1] == 1)
    printf("%lld\n", out[0]);
  else if (out[0] > out[1]) {
    long long int temp = out[0] / out[1];
    out[0] %= out[1];
    printf("%lld %lld/%lld\n", temp, out[0], out[1]);
  } else
    printf("%lld/%lld\n", out[0], out[1]);
  return 0;
}