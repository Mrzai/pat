# 1029 Median
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

### Input Specification:

Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N ($$\le 2\times 10^5$$) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of **long int**.

### Output Specification:

For each test case you should output the median of the two given sequences in a line.

### Sample Input:
```in
4 11 12 13 14
5 9 10 15 16 17
```

### Sample Output:
```out
13
```

```cpp
#include <iostream>
#define maxsize 200010
using namespace std;
int s1[maxsize] = {0};
int main() {
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d", s1 + i);
  }
  int cnt = 0, i = 0, n, temp, k;
  cin >> n;
  k = (m + n + 1) / 2;
  while (n--) {
    scanf("%d", &temp);
    while (i < m && s1[i] < temp) {
      cnt++;
      if (cnt == k) {
        cout << s1[i];
        return 0;
      }
      i++;
    }
    cnt++;
    if (cnt == k) {
      cout << temp;
      return 0;
    }
  }
  while (i < m) {
    cnt++;
    if (cnt == k) {
      cout << s1[i];
      return 0;
    }
    i++;
  }
}
```