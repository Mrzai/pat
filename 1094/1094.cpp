#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> v;
vector<int> h(100);
vector<int> num(100);

void dfs(int root, int height) {
  num[height]++;
  for (int i = 0; i < v[root].size(); i++) {
    dfs(v[root][i], height + 1);
  }
}

int main() {
  int n, m, maxnum = 0, maxnumh = 0;
  cin >> n >> m;
  v.resize(100);
  for (int i = 0, index, num; i < m; i++) {
    scanf("%d %d", &index, &num);
    for (int j = 0, temp; j < num; j++) {
      scanf("%d", &temp);
      v[index].push_back(temp);
    }
  }
  dfs(1, 1);
  for (int i = 0; i < 100; i++) {
    if (num[i] > maxnum) {
      maxnum = num[i];
      maxnumh = i;
    }
  }
  cout << maxnum << ' ' << maxnumh;
  return 0;
}