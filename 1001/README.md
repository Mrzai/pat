# 1001 A+B Format
Calculate $$a + b$$ and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

### Input Specification:

Each input file contains one test case. Each case contains a pair of integers $$a$$ and $$b$$ where $$-10^6 \le a, b \le 10^6$$. The numbers are separated by a space.

### Output Specification:

For each test case, you should output the sum of $$a$$ and $$b$$ in one line. The sum must be written in the standard format.

### Sample Input:
```in
-1000000 9
```

### Sample Output:
```out
-999,991
```
```cpp
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
```