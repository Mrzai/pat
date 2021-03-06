# 1051 Pop Sequence
Given a stack which can keep $$M$$ numbers at most.  Push $$N$$ numbers in the order of 1, 2, 3, ..., $$N$$ and pop randomly.  You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack.  For example, if $$M$$ is 5 and $$N$$ is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

### Input Specification:

Each input file contains one test case.  For each case, the first line contains 3 numbers (all no more than 1000): $$M$$ (the maximum capacity of the stack), $$N$$ (the length of push sequence), and $$K$$ (the number of pop sequences to be checked).  Then $$K$$ lines follow, each contains a pop sequence of $$N$$ numbers.  All the numbers in a line are separated by a space.

### Output Specification:

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

### Sample Input:
```in
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
```

### Sample Output:
```out
YES
NO
NO
YES
NO
```
```cpp
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  int m, n, k;
  scanf("%d %d %d", &m, &n, &k);
  for (int i = 0; i < k; i++) {
    stack<int> s;
    bool flag = false;
    int btemp = 0, ntemp;
    for (int j = 0, q = 1; j < n; j++) {
      scanf("%d", &ntemp);
      if (flag) continue;
      if (ntemp > btemp) {
        for (; q <= ntemp; q++) {
          s.push(q);
          if (s.size() > m) {
            flag = true;
            break;
          }
        }
        s.pop();
      } else {
        if (s.empty() || s.top() != ntemp) {
          flag = true;
        }
        s.pop();
      }
      btemp = ntemp;
    }
    if (!flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
```