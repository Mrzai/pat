#include <cstdio>
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  map<string, set<int>> m;
  int n, k;
  cin >> n >> k;
  while (k--) {
    int i, j;
    cin >> i >> j;
    while (j--) {
      string temp;
      cin >> temp;
      if (m.count(temp)) {
        m[temp].insert(i);
      } else {
        set<int> s;
        s.insert(i);
        m[temp] = s;
      }
    }
  }
  while (n--) {
    string temp;
    cin >> temp;
    cout << temp;
    if (m.count(temp)) {
      cout << ' ' << m[temp].size();
      for (auto it = m[temp].begin(); it != m[temp].end(); it++) {
        cout << ' ' << *it;
      }
    } else
      cout << " 0";
    cout << endl;
  }
  return 0;
}