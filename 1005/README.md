# 1005 Spell It Right
Given a non-negative integer $$N$$, your task is to compute the sum of all the digits of $$N$$, and output every digit of the sum in English.

### Input Specification:

Each input file contains one test case. Each case occupies one line which contains an $$N$$ ($$\le 10^{100}$$).

### Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

### Sample Input:
```in
12345
```

### Sample Output:
```out
one five
```

```cpp
#include <stdio.h>

int main() {
  int flag = 0;
  int sum = 0;
  char c;
  while ((c = getchar()) != '\n') {
    sum += c - '0';
  }
  char n2e[][7] = {"zero", "one", "two",   "three", "four",
                   "five", "six", "seven", "eight", "nine"};
  if (sum / 100) {
    if (flag++) putchar(' ');
    printf("%s", n2e[sum / 100]);
  }
  if (sum % 100 / 10 || sum / 100) {
    if (flag++) putchar(' ');
    printf("%s", n2e[sum % 100 / 10]);
  }
  if (flag++) putchar(' ');
  printf("%s", n2e[sum % 10]);
  return 0;
}
```