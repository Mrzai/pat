# 1050 String Subtraction
Given two strings $$S_1$$ and $$S_2$$, $$S = S_1 - S_2$$ is defined to be the remaining string after taking all the characters in $$S_2$$ from $$S_1$$. Your task is simply to calculate $$S_1 - S_2$$ for any given strings. However, it might not be that simple to do it **fast**.

### Input Specification:

Each input file contains one test case. Each case consists of two lines which gives $$S_1$$ and $$S_2$$, respectively. The string lengths of both strings are no more than $$10^4$$. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.

### Output Specification:

For each test case, print $$S_1 - S_2$$ in one line.

### Sample Input:
```in
They are students.
aeiou
```

### Sample Output:
```out
Thy r stdnts.
```

```cpp
#include <stdio.h>

int main() {
  char s1[100000] = {0}, s2[100000] = {0};
  int hash[256] = {0};

  fgets(s1, 100000, stdin);
  fgets(s2, 100000, stdin);

  for (int i = 0; s2[i] != '\0'; i++) {
    hash[s2[i]] = 1;
  }
  for (int i = 0; s1[i] != '\0'; i++) {
    if (hash[s1[i]]) continue;
    putchar(s1[i]);
  }
  return 0;
}
```