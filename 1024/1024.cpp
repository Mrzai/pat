#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void add(string &n, string t) {
  int in = 0, len = n.size();
  for (int i = 0; i < len; i++) {
    int temp = n[i] - '0' + t[i] - '0' + in;
    n[i] = temp % 10 + '0';
    in = temp / 10;
  }
  if (in) n += '1';
  reverse(n.begin(), n.end());
}

int main() {
  int m, i;
  string n;
  cin >> n >> m;
  for (i = 0; i <= m; i++) {
    string s = n;
    reverse(s.begin(), s.end());
    if (s == n || i == m) break;
    add(n, s);
  }
  cout << n << endl << i;
}
