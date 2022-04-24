#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define maxsize 128
using namespace std;

int main() {
  int k;
  string s;
  cin >> k >> s;
  vector<int> isbroken(maxsize, -1);
  vector<int> order;
  for (int i = 0; i < s.size(); i++) {
    int cnt = 1;
    while (i + 1 < s.size() && s[i + 1] == s[i]) {
      cnt++, i++;
    }
    if (cnt % k == 0 && isbroken[(int)s[i]] == -1) {
      isbroken[(int)s[i]] = 1;
      order.push_back((int)s[i]);
    } else if (cnt % k != 0) {
      isbroken[(int)s[i]] = 0;
    }
  }
  for (int i = 0; i < order.size(); i++) {
    if (isbroken[order[i]] == 1) putchar((char)order[i]);
  }
  cout << endl;
  for (int i = 0; i < s.size();) {
    if (isbroken[(int)s[i]] == 1) {
      putchar(s[i]);
      i += k;
    } else {
      putchar(s[i++]);
    }
  }
  return 0;
}