# 1021 Deepest Root
A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called **the deepest root**.

### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer $$N$$ ($$\le 10^4$$) which is the number of nodes, and hence the nodes are numbered from 1 to $$N$$. Then $$N-1$$ lines follow, each describes an edge by given the two adjacent nodes' numbers.

### Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print `Error: K components` where `K` is the number of connected components in the graph.

### Sample Input 1:
```in
5
1 2
1 3
1 4
2 5
```

### Sample Output 1:
```out
3
4
5
```

### Sample Input 2:
```in
5
1 3
1 4
2 5
3 4
```

### Sample Output 2:
```out
Error: 2 components
```

```cpp
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define maxsize 10001
vector<vector<int>> v;
set<int> s;
vector<int> temp;
bool visited[maxsize] = {false};
int n, flag, maxheight = 0, d[maxsize] = {0}, edge[maxsize][maxsize] = {0};

void dfs(int node, int height) {
  if (height > maxheight) {
    temp.clear();
    temp.push_back(node);
    maxheight = height;
  } else if (height == maxheight) {
    temp.push_back(node);
  }
  visited[node] = true;
  for (int i = 0; i < v[node].size(); i++) {
    if (!visited[v[node][i]]) {
      dfs(v[node][i], height + 1);
    }
  }
}

int main() {
  cin >> n;
  v.resize(int(n + 1));
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i, 1);
      if (i == 1) {
        if (temp.size() != 0) flag = temp[0];
        for (int i = 0; i < temp.size(); i++) {
          s.insert(temp[i]);
        }
      }
      count++;
    }
  }
  if (count != 1) {
    cout << "Error: " << count << " components" << endl;
    return 0;
  } else {
    temp.clear();
    fill(visited + 1, visited + n + 1, false);
    dfs(flag, 1);
    for (int i = 0; i < temp.size(); i++) {
      s.insert(temp[i]);
    }
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
      cout << *it << endl;
    }
  }
  return 0;
}
```