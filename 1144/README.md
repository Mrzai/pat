# 1144 The Missing Number
Given N integers, you are supposed to find the smallest positive integer that is NOT in the given list.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N ($$\le 10^5$$). Then N integers are given in the next line, separated by spaces. All the numbers are in the range of **int**.

### Output Specification:

Print in a line the smallest positive integer that is missing from the input list.

### Sample Input:
```in
10
5 -25 9 6 1 3 4 2 5 17
```

### Sample Output:
```out
7
```

```cpp
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, k = 10;
  cin >> n;
  map<int, int> mp;
  for (int i = 0, temp; i < n; i++) {
    scanf("%d", &temp);
    mp[temp]++;
  }
  while (++k) {
    if (!mp[k]) break;
  }
  cout << k << endl;
  return 0;
}
```