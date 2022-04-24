# 1090 Highest Price in Supply Chain
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price $$P$$ and sell or distribute them in a price that is $$r$$% higher than $$P$$. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.

### Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: $$N$$ ($$\le 10^5$$), the total number of the members in the supply chain (and hence they are numbered from 0 to $$N-1$$); $$P$$, the price given by the root supplier; and $$r$$, the percentage rate of price increment for each distributor or retailer. Then the next line contains $$N$$ numbers, each number $$S_i$$ is the index of the supplier for the $$i$$-th member. $$S_{root}$$ for the root supplier is defined to be $$-1$$. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price will not exceed $$10^{10}$$.

### Sample Input:
```in
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
```

### Sample Output:
```out
1.85 2
```

```cpp
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v;
int n, root, cnt, maxh;

void dfs(int i, int depth) {
  if (v[i].empty()) {
    if (depth == maxh)
      cnt++;
    else if (depth > maxh) {
      cnt = 1;
      maxh = depth;
    }
    return;
  }
  for (int j = 0; j < v[i].size(); j++) {
    dfs(v[i][j], depth + 1);
  }
}

int main() {
  double p, r;
  cin >> n >> p >> r;
  v.resize(n);
  for (int i = 0, index; i < n; i++) {
    scanf("%d", &index);
    if (index != -1)
      v[index].push_back(i);
    else
      root = i;
  }
  dfs(root, 0);
  printf("%.2lf %d", p * pow(1 + r / 100, maxh), cnt);
  return 0;
}
```