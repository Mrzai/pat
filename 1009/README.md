# 1009 Product of Polynomials
This time, you are supposed to find $$A\times B$$ where $$A$$ and $$B$$ are two polynomials.

### Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

$$K$$ $$N_1$$ $$a_{N_1}$$ $$N_2$$ $$a_{N_2}$$ ... $$N_K$$ $$a_{N_K}$$

where $$K$$ is the number of nonzero terms in the polynomial, $$N_i$$ and $$a_{N_i}$$ ($$i=1, 2, \cdots , K$$) are the exponents and coefficients, respectively.  It is given that $$1\le K \le 10$$, $$0 \le N_K < \cdots < N_2 < N_1 \le 1000$$.  


### Output Specification:

For each test case you should output the product of $$A$$ and $$B$$ in one line, with the same format as the input.  Notice that there must be **NO** extra space at the end of each line.  Please be accurate up to 1 decimal place. 

### Sample Input:
```in
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```

### Sample Output:
```out
3 3 3.6 2 6.0 1 1.6
```

```cpp
#include <cstdio>
#include <iostream>
#define maxsize 2001
using namespace std;

int main() {
  int k, count = 0;
  float po[maxsize] = {0}, out[maxsize] = {0};
  scanf("%d", &k);
  while (k--) {
    int ex;
    float re;
    scanf("%d %f", &ex, &re);
    po[ex] += re;
  }
  scanf("%d", &k);
  while (k--) {
    int ex;
    float re;
    scanf("%d %f", &ex, &re);
    for (int i = 0; i <= 1000; i++) {
      if (po[i] != 0) {
        out[i + ex] += re * po[i];
      }
    }
  }
  for (int i = maxsize - 1; i >= 0; i--) {
    if (out[i] != 0) {
      count++;
    }
  }
  cout << count;
  for (int i = maxsize - 1; i >= 0; i--) {
    if (out[i] != 0) {
      printf(" %d %.1f", i, out[i]);
    }
  }
  return 0;
}
```