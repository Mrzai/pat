# 1078 Hashing
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers.  The hash function is defined to be $$H(key) = key \% TSize$$ where $$TSize$$ is the maximum size of the hash table.  Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime.  If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

### Input Specification:

Each input file contains one test case.  For each case, the first line contains two positive numbers: $$MSize$$ ($$\le 10^4$$) and $$N$$ ($$\le MSize$$) which are the user-defined table size and the number of input numbers, respectively.  Then $$N$$ distinct positive integers are given in the next line.  All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line.  All the numbers in a line are separated by a space, and there must be no extra space at the end of the line.  In case it is impossible to insert the number, print "-" instead.

### Sample Input:
```in
4 4
10 6 4 15
```

### Sample Output:
```out
0 1 4 -
```
```cpp
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
```