# 1056 Mice and Rice
**Mice and Rice** is the name of a programming contest in which each programmer must write a piece of code to control the movements of a mouse in a given map. The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.

First the playing order is randomly decided for $$N_P$$ programmers. Then every $$N_G$$ programmers are grouped in a match. The fattest mouse in a group wins and enters the next turn. All the losers in this turn are ranked the same. Every $$N_G$$ winners are then grouped in the next match until a final winner is determined.

For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code. Given the weights of all the mice and the initial playing order, you are supposed to output the ranks for the programmers.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: $$N_P$$ and $$N_G$$ ($$\le 1000$$), the number of programmers and the maximum number of mice in a group, respectively. If there are less than $$N_G$$ mice at the end of the player's list, then all the mice left will be put into the last group. The second line contains $$N_P$$ distinct non-negative numbers $$W_i$$ ($$i=0,\cdots ,N_P -1$$) where each $$W_i$$ is the weight of the $$i$$-th mouse respectively. The third line gives the initial playing order which is a permutation of $$0,\cdots ,N_P -1$$ (assume that the programmers are numbered from 0 to $$N_P -1$$). All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print the final ranks in a line. The $$i$$-th number is the rank of the $$i$$-th programmer, and all the numbers must be separated by a space, with no extra space at the end of the line.

### Sample Input:
```in
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
```

### Sample Output:
```out
5 5 5 2 5 5 5 3 1 3 5
```

```cpp
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct mice {
  int rank = 0, weight;
};

int main() {
  int np, ng;
  cin >> np >> ng;
  vector<mice> v(np);
  vector<int> order(np), temp;

  for (int i = 0; i < np; i++) {
    scanf("%d", &v[i].weight);
  }
  for (int i = 0; i < np; i++) {
    scanf("%d", &order[i]);
  }

  while (true) {
    if (order.size() == 1) {
      v[order[0]].rank = 1;
      break;
    }
    int k = order.size() % ng ? order.size() / ng + 2 : order.size() / ng + 1;
    if (order.size() == 1) k = 1;
    for (int i = 0; i < order.size(); i++) {
      v[order[i]].rank = k;
    }
    for (int i = 0; i < k - 1; i++) {
      int low = i * ng;
      int high = low + ng < order.size() ? low + ng : order.size();
      int maxkey = order[low];
      int maxw = v[order[low++]].weight;
      while (low < high) {
        if (v[order[low]].weight > maxw) {
          maxw = v[order[low]].weight;
          maxkey = order[low];
        }
        low++;
      }
      temp.push_back(maxkey);
    }
    order.assign(temp.begin(), temp.end());
    temp.clear();
  }

  for (int i = 0; i < np; i++) {
    if (i) putchar(' ');
    printf("%d", v[i].rank);
  }
  return 0;
}
```