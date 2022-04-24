#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string s;
  cin >> s >> n;
  while (--n) {
    string temp;
    for (int i = 1, cnt = 1; i <= s.size(); i++) {
      if (i != s.size() && s[i] == s[i - 1])
        cnt++;
      else {
        temp += s[i - 1] + to_string(cnt);
        cnt = 1;
      }
    }
    s = temp;
  }
  cout << s << endl;
  return 0;
}