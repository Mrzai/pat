#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n, m, x, y, k;
  cin >> n >> m;
  vector<vector<int>> edge(n);
  while (m--) {
    scanf("%d %d", &x, &y);
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  cin >> k;
  while (k--) {
    set<int> s;
    vector<int> v(n, -1);
    bool flag = true;
    for (int i = 0, temp; i < n; i++) {
      scanf("%d", &temp);
      if (!flag) continue;
      for (auto it : edge[i]) {
        if (v[it] == temp) {
          flag = false;
          continue;
        }
      }
      s.insert(temp);
      v[i] = temp;
    }
    if (flag)
      cout << s.size() << "-coloring" << endl;
    else
      cout << "No" << endl;
  }
}