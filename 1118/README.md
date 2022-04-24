# 1118 Birds in Forest
Some scientists took pictures of thousands of birds in a forest. Assume that all the birds appear in the same picture belong to the same tree. You are supposed to help the scientists to count the maximum number of trees in the forest, and for any pair of birds, tell if they are on the same tree.

### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number $$N$$ ($$\le 10^4$$) which is the number of pictures. Then $$N$$ lines follow, each describes a picture in the format:

$$K$$ $$B_1$$ $$B_2$$ ... $$B_K$$

where $$K$$ is the number of birds in this picture, and $$B_i$$'s are the indices of birds. It is guaranteed that the birds in all the pictures are numbered continuously from 1 to some number that is no more than $$10^4$$.

After the pictures there is a positive number $$Q$$ ($$\le 10^4$$) which is the number of queries. Then $$Q$$ lines follow, each contains the indices of two birds.

### Output Specification:

For each test case, first output in a line the maximum possible number of trees and the number of birds. Then for each query, print in a line `Yes` if the two birds belong to the same tree, or `No` if not.

### Sample Input:
```in
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
```

### Sample Output:
```out
2 10
Yes
No
```

```cpp
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define maxsize 10010
using namespace std;
vector<int> father(maxsize);

void initfather() {
  for (int i = 0; i < maxsize; i++) {
    father[i] = i;
  }
}

int find(int x) {
  int temp = x;
  while (x != father[x]) {
    x = father[x];
  }
  while (temp != father[temp]) {
    int n = temp;
    temp = father[temp];
    father[n] = x;
  }
  return x;
}

void Union(int x, int y) {
  int fa = find(x);
  int fb = find(y);
  if (fa != fb) father[fb] = fa;
}

int main() {
  initfather();
  int n, qt, treenum = 0, birdnum = 0;
  cin >> n;
  vector<bool> visited(maxsize);
  for (int i = 0, k; i < n; i++) {
    cin >> k;
    for (int j = 0, temp, fa; j < k; j++) {
      scanf("%d", &temp);
      if (j == 0) fa = temp;
      if (visited[temp]) Union(find(temp), find(fa));
      Union(fa, temp);
      visited[temp] = true;
    }
  }
  for (int i = 0; i < maxsize; i++) {
    if (visited[i]) {
      birdnum++;
      if (father[i] == i) treenum++;
    }
  }
  cout << treenum << ' ' << birdnum << endl;
  cin >> qt;
  for (int i = 0, qa, qb; i < qt; i++) {
    scanf("%d %d", &qa, &qb);
    if (find(qa) == find(qb)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
```