# 1027 Colors in Mars
People in Mars represent the colors in their computers in a similar way as the Earth people. That is, a color is represented by a 6-digit number, where the first 2 digits are for `Red`, the middle 2 digits for `Green`, and the last 2 digits for `Blue`. The only difference is that they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.

### Input Specification:

Each input file contains one test case which occupies a line containing the three decimal color values.

### Output Specification:

For each test case you should output the Mars RGB value in the following format: first output `#`, then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a `0` to its left.

### Sample Input:
```in
15 43 71
```

### Sample Output:
```out
#123456
```

```cpp
#include <stdio.h>

int main() {
  int in[3];
  char output[14] = {"0123456789ABC"};
  scanf("%d%d%d", in, in + 1, in + 2);
  putchar('#');
  for (int i = 0; i < 3; i++) {
    if (in[i] / 13)
      printf("%c", output[in[i] / 13]);
    else
      putchar('0');
    putchar(output[in[i] % 13]);
  }
}
```