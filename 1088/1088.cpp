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