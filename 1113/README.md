# 1113 Integer Set Partition
Given a set of $$N$$ ($$> 1$$) positive integers, you are supposed to partition them into two disjoint sets $$A_1$$ and $$A_2$$ of $$n_1$$ and $$n_2$$ numbers, respectively. Let $$S_1$$ and $$S_2$$ denote the sums of all the numbers in $$A_1$$ and $$A_2$$, respectively. You are supposed to make the partition so that $$|n_1 - n_2|$$ is minimized first, and then $$|S_1 - S_2|$$ is maximized.

### Input Specification:

Each input file contains one test case. For each case, the first line gives an integer $$N$$ ($$2 \le N \le 10^5$$), and then $$N$$ positive integers follow in the next line, separated by spaces. It is guaranteed that all the integers and their sum are less than $$2^{31}$$.

### Output Specification:

For each case, print in a line two numbers: $$|n_1 - n_2|$$ and $$|S_1 - S_2|$$, separated by exactly one space.

### Sample Input 1:
```in
10
23 8 10 99 46 2333 46 1 666 555
```

### Sample Output 1:
```out
0 3611
```

### Sample Input 2:
```in
13
110 79 218 69 3721 100 29 135 2 6 13 5188 85
```

### Sample Output 2:
```out
1 9359
```

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, sum = 0, halfsum = 0;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    sum += v[i];
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n / 2; i++) halfsum += v[i];
  printf("%d %d", n % 2, sum - 2 * halfsum);
  return 0;
}
```