# 1088 Rational Arithmetic
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.

### Input Specification:

Each input file contains one test case, which gives in one line the two rational numbers in the format `a1/b1 a2/b2`. The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.

### Output Specification:

For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is `number1 operator number2 = result`. Notice that all the rational numbers must be in their simplest form `k a/b`, where `k` is the integer part, and `a/b` is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output `Inf` as the result. It is guaranteed that all the output integers are in the range of **long int**.

### Sample Input 1:
```in
2/3 -4/2
```

### Sample Output 1:
```out
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
```

### Sample Input 2:
```in
5/3 0/6
```

### Sample Output 2:
```out
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
```

```cpp
#include <cstdio>
#include <iostream>
using namespace std;
long long int a[2] = {0}, b[2] = {0}, temp[2] = {0}, inf = 0;
void simplify(long long int *in);
void add();
void sub();
void mu();
void re_mu();

long long int GCD(long long int i, long long int j) {
  return j == 0 ? i : GCD(j, i % j);
}

int main() {
  scanf("%lld/%lld", a, a + 1);
  scanf("%lld/%lld", b, b + 1);
  simplify(a);
  simplify(b);
  add();
  sub();
  mu();
  re_mu();
  return 0;
}

void out(long long int *k) {
  if (inf == 1) {
    printf("Inf");
    return;
  }

  if (k[0] > 0) {
    if (k[0] / k[1]) printf("%lld", k[0] / k[1]);
    if (k[0] / k[1] && k[0] % k[1]) putchar(' ');
    if (k[0] % k[1]) printf("%lld/%lld", k[0] % k[1], k[1]);
  } else if (k[0] == 0)
    putchar('0');
  else {
    putchar('(');
    if (k[0] / k[1]) printf("%lld", k[0] / k[1]);
    if (k[0] / k[1] && k[0] % k[1]) putchar(' ');
    if (!(k[0] / k[1])) putchar('-');
    if (k[0] % k[1]) printf("%lld/%lld", -k[0] % k[1], k[1]);
    putchar(')');
  }
}

void simplify(long long int *in) {
  int gcd = GCD(abs(in[0]), in[1]);
  in[0] /= gcd;
  in[1] /= gcd;
}

void add() {
  temp[0] = a[0] * b[1] + a[1] * b[0];
  temp[1] = a[1] * b[1];
  simplify(temp);
  out(a);
  printf(" + ");
  out(b);
  printf(" = ");
  out(temp);
  putchar('\n');
}

void sub() {
  temp[0] = a[0] * b[1] - a[1] * b[0];
  temp[1] = a[1] * b[1];
  simplify(temp);
  out(a);
  printf(" - ");
  out(b);
  printf(" = ");
  out(temp);
  putchar('\n');
}

void mu() {
  temp[0] = a[0] * b[0];
  temp[1] = a[1] * b[1];
  simplify(temp);
  out(a);
  printf(" * ");
  out(b);
  printf(" = ");
  out(temp);
  putchar('\n');
}

void re_mu() {
  if (b[0] == 0) {
    out(a);
    printf(" / ");
    out(b);
    printf(" = ");
    inf = 1;
    out(temp);
    putchar('\n');
    return;
  }
  temp[0] = a[0] * b[1];
  temp[1] = a[1] * b[0];
  if (temp[1] < 0) {
    temp[0] = -temp[0];
    temp[1] = -temp[1];
  }
  simplify(temp);
  out(a);
  printf(" / ");
  out(b);
  printf(" = ");
  out(temp);
  putchar('\n');
}
```