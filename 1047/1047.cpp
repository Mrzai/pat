#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
char name[40010][5];
vector<int> v[2510];
bool cmp(int i, int j) { return strcmp(name[i], name[j]) < 0; }
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1, num; i <= n; i++) {
    scanf("%s %d", name[i], &num);
    for (int j = 0, m; j < num; j++) {
      scanf("%d", &m);
      v[m].push_back(i);
    }
  }
  for (int i = 1; i <= k; i++) {
    printf("%d %d\n", i, (int)v[i].size());
    sort(v[i].begin(), v[i].end(), cmp);
    for (auto it = v[i].begin(); it != v[i].end(); it++) {
      printf("%s\n", name[*it]);
    }
  }
  return 0;
}