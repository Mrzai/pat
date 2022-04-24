#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int m, n, s;
  bool flag = false;
  cin >> m >> n >> s;
  string temp;
  map<string, bool> m2b;
  vector<string> v;
  for (int i = 1; i <= m; i++) {
    cin >> temp;
    if (i != s) continue;
    if (!m2b[temp]) {
      cout << temp << endl;
      s += n;
      flag = true;
      m2b[temp] = true;
    } else
      s += 1;
  }
  if (!flag) cout << "Keep going..." << endl;
  return 0;
}