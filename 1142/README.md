# 1142 Maximal Clique
A **clique** is a subset of vertices of an undirected graph such that every two distinct vertices in the clique are adjacent. A **maximal clique** is a clique that cannot be extended by including one more adjacent vertex. (Quoted from https://en.wikipedia.org/wiki/Clique_(graph_theory))

Now it is your job to judge if a given subset of vertices can form a maximal clique.

### Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers Nv ($$\le$$ 200), the number of vertices in the graph, and Ne, the number of undirected edges. Then Ne lines follow, each gives a pair of vertices of an edge. The vertices are numbered from 1 to Nv.

After the graph, there is another positive integer M ($$\le$$ 100). Then M lines of query follow, each first gives a positive number K ($$\le$$ Nv), then followed by a sequence of K distinct vertices. All the numbers in a line are separated by a space.

### Output Specification:

For each of the M queries, print in a line `Yes` if the given subset of vertices can form a maximal clique; or if it is a clique but not a **maximal clique**, print `Not Maximal`; or if it is not a clique at all, print `Not a Clique`.

### Sample Input:
```in
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1
```

### Sample Output:
```out
Yes
Yes
Yes
Yes
Not Maximal
Not a Clique
```

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isClique(vector<vector<bool>>& edge, vector<int>& temp) {
  bool flag = true;
  for (auto i : temp) {
    for (auto j : temp) {
      if (i != j && !edge[i][j]) {
        flag = false;
        break;
      }
    }
    if (!flag) break;
  }
  return flag;
}

bool isMax(vector<vector<bool>>& edge, vector<int>& temp) {
  bool flag = true;
  vector<bool> visited(edge.size());
  for (auto it : temp) {
    visited[it] = true;
  }
  for (int i = 1; i < edge.size(); i++) {
    if (!visited[i]) {
      auto it = temp.begin();
      while (it != temp.end() && edge[*it][i]) it++;
      if (it == temp.end()) flag = false;
    }
    if (!flag) break;
  }
  return flag;
}

int main() {
  ios::sync_with_stdio(false);
  int nv, ne, k;
  cin >> nv >> ne;
  vector<vector<bool>> edge(nv + 1, vector<bool>(nv + 1));
  for (int i = 0; i < ne; i++) {
    int x, y;
    cin >> x >> y;
    edge[x][y] = edge[y][x] = true;
  }
  cin >> k;
  for (int i = 0, len; i < k; i++) {
    cin >> len;
    vector<int> temp;
    for (int j = 0; j < len; j++) {
      int index;
      cin >> index;
      temp.push_back(index);
    }
    if (isClique(edge, temp))
      cout << (isMax(edge, temp) ? "Yes" : "Not Maximal") << endl;
    else
      cout << "Not a Clique" << endl;
  }
  return 0;
}
```