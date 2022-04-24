# 1145 Hashing - Average Search Time
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table first.  Then try to find another sequence of integer keys from the table and output the average search time (the number of comparisons made to find whether or not the key is in the table). The hash function is defined to be $$H(key) = key \% TSize$$ where $$TSize$$ is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 3 positive numbers: MSize, N, and M, which are the user-defined table size, the number of input numbers, and the number of keys to be found, respectively. All the three numbers are no more than $$10^4$$.  Then N distinct positive integers are given in the next line, followed by M positive integer keys in the next line. All the numbers in a line are separated by a space and are no more than $$10^5$$.

### Output Specification:

For each test case, in case it is impossible to insert some number, print in a line `X cannot be inserted.` where `X` is the input number. Finally print in a line the average search time for all the M keys, accurate up to 1 decimal place.

### Sample Input:
```in
4 5 4
10 6 4 15 11
11 4 15 2
```

### Sample Output:
```out
15 cannot be inserted.
2.8
```

```cpp
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
  if (x == 1 || x == 0) {
    return false;
  }
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int msize, n, m, cnt = 0;
  cin >> msize >> n >> m;
  while (!isPrime(msize)) msize++;
  vector<int> hashtable(msize);
  for (int i = 0, index; i < n; i++) {
    int k = 0;
    scanf("%d", &index);
    while (k < msize && hashtable[(index + k * k) % msize]) k++;
    if (hashtable[(index + k * k) % msize])
      cout << index << " cannot be inserted." << endl;
    else
      hashtable[(index + k * k) % msize] = index;
  }
  for (int i = 0, index; i < m; i++) {
    scanf("%d", &index);
    for (int k = 0; k <= msize; k++) {
      cnt++;
      if (hashtable[(index + k * k) % msize] == index ||
          !hashtable[(index + k * k) % msize])
        break;
    }
  }
  printf("%.1f", float(cnt) / m);
  return 0;
}
```