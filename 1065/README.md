# 1065 A+B and C (64bit)
Given three integers $$A$$, $$B$$ and $$C$$ in ($$-2^{63}, 2^{63}$$), you are supposed to tell whether $$A+B > C$$.

### Input Specification:

The first line of the input gives the positive number of test cases, $$T$$ ($$\le 10$$). Then $$T$$ test cases follow, each consists of a single line containing three integers $$A$$, $$B$$ and $$C$$, separated by single spaces.

### Output Specification:

For each test case, output in one line `Case #X: true` if $$A+B>C$$, or `Case #X: false` otherwise, where $$X$$ is the case number (starting from 1). Each line should ends with ```'\n'```.

### Sample Input:
```in
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
```

### Sample Output:
```out
Case #1: false
Case #2: true
Case #3: false
```

**Thanks to Jiwen Lin for amending the test data.**
```cpp
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

```