# 1015 Reversible Primes
A **reversible prime** in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers $$N$$ ($$< 10^5$$) and $$D$$ ($$1 < D \le 10$$), you are supposed to tell if $$N$$ is a reversible prime with radix $$D$$.

### Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two integers $$N$$ and $$D$$. The input is finished by a negative $$N$$.

### Output Specification:

For each test case, print in one line `Yes` if $$N$$ is a reversible prime with radix $$D$$, or `No` if not.

### Sample Input:
```in
73 10
23 2
23 10
-2
```

### Sample Output:
```out
Yes
Yes
No
```

```cpp
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

```