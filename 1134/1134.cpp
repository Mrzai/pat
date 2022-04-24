#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, k, legalnode = 0;
  scanf("%d %d", &n, &m);
  vector<vector<int>> v(n);
  for (int i = 0, x, y; i < m; i++) {
    scanf("%d %d", &x, &y);
    v[x].push_back(i);
    v[y].push_back(i);
  }
  scanf("%d", &k);
  for (int i = 0, len; i < k; i++) {
    vector<bool> visited(m);
    scanf("%d", &len);
    for (int i = 0, vi; i < len; i++) {
      scanf("%d", &vi);
      for (int j = 0; j < v[vi].size(); j++) {
        visited[v[vi][j]] = true;
      }
    }
    bool flag = true;
    for (auto it : visited) {
      if (!it) {
        flag = false;
        break;
      }
    }
    cout << (flag ? "Yes" : "No") << endl;
  }
  return 0;
}