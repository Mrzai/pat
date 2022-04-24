#include <iostream>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    long long sum = a + b;
    printf("Case #%d: ", i);
    if (a > 0 && b > 0 && sum < 0) {
      printf("true\n");
    } else if (a < 0 && b < 0 && sum >= 0) {
      printf("false\n");
    } else {
      printf(sum > c ? "true\n" : "false\n");
    }
  }
  return 0;
}
