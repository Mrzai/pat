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