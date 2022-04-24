#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m;
  vector<int> ntopo;
  vector<int> indgree(n + 1);
  vector<vector<bool>> edge(n + 1, vector<bool>(n + 1));
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    indgree[y]++;
    edge[x][y] = 1;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    bool flag = false;
    vector<int> temp = indgree;
    for (int j = 0, index; j < n; j++) {
      scanf("%d", &index);
      if (temp[index]) flag = true;
      if (flag) continue;
      for (int q = 1; q <= n; q++) {
        if (edge[index][q]) temp[q]--;
      }
    }
    if (flag) ntopo.push_back(i);
  }
  for (int i = 0; i < ntopo.size(); i++) {
    if (i) putchar(' ');
    printf("%d", ntopo[i]);
  }
  return 0;
}