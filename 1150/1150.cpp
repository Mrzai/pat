#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#define max 0x7fffffff
using namespace std;

int main() {
  int n, m, k, x, y, dist, minid, min = max;
  cin >> n >> m;
  vector<vector<int>> edge(n + 1, vector<int>(n + 1));
  while (m--) {
    scanf("%d %d %d", &x, &y, &dist);
    edge[x][y] = edge[y][x] = dist;
  }
  cin >> k;
  for (int i = 1; i <= k; i++) {
    bool isCycle = true, isSimple = true;
    int cnt = 0, num = 0, len;
    cout << "Path " << i << ": ";
    cin >> len;
    vector<int> path(len);
    vector<bool> visited(n + 1);
    for (int i = 0, index; i < len; i++) {
      scanf("%d", &path[i]);
    }
    if (path[0] != path[len - 1]) {
      isCycle = false;
    }
    for (int j = 1; j < len; j++) {
      if (visited[path[j]]) {
        isSimple = false;
      } else {
        num++;
        visited[path[j]] = true;
      }
      if (!edge[path[j]][path[j - 1]]) {
        isCycle = false;
        cnt = max;
        break;
      }
      cnt += edge[path[j]][path[j - 1]];
    }
    if (num != n) isCycle = false;
    if (isCycle && cnt < min) {
      minid = i;
      min = cnt;
    }
    cout << (cnt == max ? "NA" : to_string(cnt));
    if (isSimple && isCycle)
      cout << " (TS simple cycle)" << endl;
    else if (isCycle)
      cout << " (TS cycle)" << endl;
    else
      cout << " (Not a TS cycle)" << endl;
  }
  cout << "Shortest Dist(" << minid << ") = " << min << endl;
  return 0;
}