#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define INT_MAX 0x7fffffff
using namespace std;

int minh = INT_MAX, minnum = 0;
vector<vector<int>> v;
void dfs(int root, int height) {
  if (v[root].empty()) {
    if (minh == height) {
      minnum++;
    } else if (height < minh) {
      minnum = 1;
      minh = height;
    }
    return;
  }
  for (int i = 0; i < v[root].size(); i++) {
    dfs(v[root][i], height + 1);
  }
}

int main() {
  int n;
  double p, r;
  cin >> n >> p >> r;
  v.resize(n);
  for (int i = 0, num; i < n; i++) {
    scanf("%d", &num);
    for (int j = 0, temp; j < num; j++) {
      scanf("%d", &temp);
      v[i].push_back(temp);
    }
  }
  dfs(0, 0);
  printf("%.4lf %d", p * pow(1 + r / 100, minh), minnum);
  return 0;
}