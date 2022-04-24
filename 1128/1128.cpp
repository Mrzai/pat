#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int k, n;
  vector<int> column;
  cin >> k;
  while (k--) {
    bool flag = true;
    scanf("%d", &n);
    column.resize(n);
    for (int x = 0, y; x < n; x++) {
      scanf("%d", &y);
      if (!flag) continue;
      column[x] = y;
      for (int i = 0; i < x; i++) {
        if (column[i] == column[x] ||
            abs(column[x] - column[i]) == abs(x - i)) {
          flag = false;
          break;
        }
      }
    }
    column.clear();
    cout << (flag ? "YES" : "NO") << endl;
  }
  return 0;
}