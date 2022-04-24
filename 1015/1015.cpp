#include <math.h>
#include <stdio.h>

int IsPrime(int);
int Reverse(int, int);

int main() {
  int flag = 0, input_num = 0, input_radix = 0;

  while (1) {
    scanf("%d", &input_num);
    if (input_num < 0) break;
    scanf("%d", &input_radix);
    if (IsPrime(input_num) && IsPrime(Reverse(input_num, input_radix)))
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}

int IsPrime(int i) {
  if (i <= 1) return 0;
  for (int j = 2; j <= sqrt(i); j++) {
    if (i % j == 0) {
      return 0;
    }
  }
  return 1;
}

int Reverse(int i, int j) {
  int str[20], len = 0, sum = 0;
  while (i != 0) {
    str[len++] = i % j;
    i /= j;
  }
  for (int k = 0; k < len; k++) {
    sum = sum * j + str[k];
  }
  return sum;
}
