#include <iostream>
#include <map>
#include <vector>
#define maxsize 100000
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> mp;
  while (n--) {
    int x, y;
    cin >> x >> y;
    mp[x].push_back(y);
    mp[y].push_back(x);
  }
  while (m--) {
    int len, temp;
    vector<bool> visited(maxsize);
    cin >> len;
    bool flag = true;
    while (len--) {
      cin >> temp;
      if (!flag) continue;
      if (visited[temp]) {
        flag = false;
        continue;
      }
      for (auto it : mp[temp]) {
        visited[it] = true;
      }
    }
    cout << (flag ? "Yes" : "No") << endl;
  }
  return 0;
}