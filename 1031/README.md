# 1031 Hello World for U
Given any string of $$N$$ ($$\ge 5$$) characters, you are asked to form the characters into the shape of `U`. For example, `helloworld` can be printed as:
```
h  d
e  l
l  r
lowo
```

That is, the characters must be printed in the original order, starting top-down from the left vertical line with $$n_1$$ characters, then left to right along the bottom line with $$n_2$$ characters, and finally bottom-up along the vertical line with $$n_3$$ characters. And more, we would like `U` to be as squared as possible -- that is, it must be satisfied that $$n_1 = n_3 = max$$ { $$k$$ | $$k \le n_2$$ for all $$3 \le n_2 \le N$$ } with $$n_1 + n_2 + n_3 - 2 = N$$.

### Input Specification:

Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

### Output Specification:

For each test case, print the input string in the shape of U as specified in the description.

### Sample Input:
```in
helloworld!
```

### Sample Output:
```out
h   !
e   d
l   l
lowor
```

```cpp
#include <stdio.h>
#include <string.h>

int output(char* str, int n1, int n2, int n3, int n);

int main() {
  char str[100] = {0};
  int n = 0, n1 = 0, n2 = 0, n3 = 0;
  scanf("%s", str);
  n = strlen(str);
  n2 = (n + 2) / 3 + (n + 2) % 3;
  n1 = n3 = (n + 2) / 3;
  output(str, n1, n2, n3, n);
  return 0;
}

int output(char* str, int n1, int n2, int n3, int n) {
  for (int i = 0; i < n1; i++) {
    if (i < n1 - 1) {
      putchar(str[i]);
      for (int j = 0; j < n2 - 2; j++) putchar(' ');
      putchar(str[n - i - 1]);
      putchar('\n');
    } else {
      while (i < n - n1 + 1) {
        putchar(str[i++]);
      }
    }
  }
  return 0;
}
```