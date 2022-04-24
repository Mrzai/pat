#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<bool>>& edge, int root) {
  static vector<bool> visited(edge.size());
  static int cnt = 0;
  cnt++;
  visited[root] = true;
  bool flag = cnt == edge.size() ? true : false;
  for (int i = 0; i < edge.size(); i++) {
    if (!visited[i] && edge[root][i]) {
      flag = dfs(edge, i) || flag;
    }
  }
  return flag;
}

int main() {
  int n, m, evendig = 0;
  cin >> n >> m;
  vector<vector<bool>> edge(n, vector<bool>(n));
  vector<int> indigree(n);
  for (int i = 0, x, y; i < m; i++) {
    scanf("%d %d", &x, &y);
    edge[x][y] = edge[--y][--x] = true;
    indigree[x]++;
    indigree[y]++;
  }
  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    if (indigree[i] % 2 == 0) evendig++;
    printf("%d", indigree[i]);
  }
  cout << endl;
  if (dfs(edge, 0)) {
    if (evendig == n) {
      cout << "Eulerian" << endl;
    } else if (evendig == n - 2) {
      cout << "Semi-Eulerian" << endl;
    } else
      cout << "Non-Eulerian" << endl;
  } else {
    cout << "Non-Eulerian" << endl;
  }
  return 0;
}