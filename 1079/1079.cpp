#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n;
double p, r, sum = 0;
vector<int> isleaves;
vector<vector<int>> v;

void dfs(int i, double price) {
  if (i) price += r * price;
  if (isleaves[i]) {
    sum += price * isleaves[i];
    return;
  }
  for (auto j = v[i].begin(); j != v[i].end(); j++) {
    dfs(*j, price);
  }
}

int main() {
  cin >> n >> p >> r;
  r /= 100;
  v.resize(n);
  isleaves.resize(n, 0);
  for (int i = 0, k; i < n; i++) {
    scanf("%d", &k);
    if (!k) {
      scanf("%d", &isleaves[i]);
      continue;
    }
    for (int j = 0, index; j < k; j++) {
      scanf("%d", &index);
      v[i].push_back(index);
    }
  }
  dfs(0, p);
  printf("%.1lf", sum);
  return 0;
}