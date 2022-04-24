#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool isprime(int k) {
  if (k == 0 || k == 1) return false;
  for (int i = 2; i <= sqrt(k); i++) {
    if (k % i == 0) return false;
  }
  return true;
}

int main() {
  int m, n, t;
  cin >> m >> n;
  while (!isprime(m)) m++;
  vector<bool> v(m, false);
  for (int i = 0, temp; i < n; i++) {
    scanf("%d", &temp);
    int h = temp % m;
    for (int j = 1; v[h] && j <= m / 2; j++) {
      h = (temp + j * j) % m;
    }
    if (i) putchar(' ');
    if (v[h])
      putchar('-');
    else {
      printf("%d", h);
      v[h] = true;
    }
  }
  return 0;
}