# 1125 Chain the Ropes
Given some segments of rope, you are supposed to chain them into one rope. Each time you may only fold two segments into loops and chain them into one piece, as shown by the figure. The resulting chain will be treated as another segment of rope and can be folded again. After each chaining, the lengths of the original two segments will be halved.


![rope.jpg](~/46293e57-aa0e-414b-b5c3-7c4b2d5201e2.jpg)


Your job is to make the longest possible rope out of $$N$$ given segments.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer $$N$$ ($$2 \le N \le 10^4$$). Then $$N$$ positive integer lengths of the segments are given in the next line, separated by spaces. All the integers are no more than $$10^4$$.

### Output Specification:

For each case, print in a line the length of the longest possible rope that can be made by the given segments. The result must be rounded to the nearest integer that is no greater than the maximum length.

### Sample Input:
```in
8
10 15 12 3 4 13 1 15
```

### Sample Output:
```out
14
```

```cpp
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i < n; i++) {
    v[0] = (v[i] + v[0]) / 2;
  }
  printf("%d", v[0]);
  return 0;
}
```