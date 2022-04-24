#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m;
  vector<int> temp;
  vector<vector<bool>> edge(n + 1, vector<bool>(n + 1, false));
  for (int i = 0, x, y; i < m; i++) {
    scanf("%d %d", &x, &y);
    edge[x][y] = edge[y][x] = true;
  }
  cin >> k;
  while (k--) {
    int num;
    cin >> num;
    vector<int> v(num);
    set<int> s;
    for (int i = 0; i < num; i++) {
      scanf("%d", &v[i]);
      s.insert(v[i]);
    }
    bool flag = true;
    if (s.size() != n || num - 1 != n || v[0] != v[num - 1]) {
      flag = false;
    } else {
      for (int i = 0; i < num - 1; i++) {
        if (!edge[v[i]][v[i + 1]]) {
          flag = false;
          break;
        }
      }
    }
    printf("%s\n", flag ? "YES" : "NO");
  }
  return 0;
}