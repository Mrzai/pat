#include <iostream>
#include <string>
using namespace std;

string getstr(string s, int n) {
  string temp = "0.";
  int index = s.find('.') != s.npos ? s.find('.') : s.size();
  int k = 0, len;
  while (s[k] == '0' || s[k] == '.') k++;
  if (index >= k)
    len = index - k;
  else
    len = index - k + 1;
  if (k == s.size()) len = 0;
  for (int i = 0; i < n;) {
    if (s[k] != '.' && k < s.size()) {
      temp += s[k];
      i++;
    } else if (k >= s.size()) {
      temp += '0';
      i++;
    }
    k++;
  }
  temp += "*10^";
  temp += to_string(len);
  return temp;
}

int main() {
  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;
  s1 = getstr(s1, n);
  s2 = getstr(s2, n);
  if (s1 == s2)
    cout << "YES" << ' ' << s1;
  else
    cout << "NO" << ' ' << s1 << ' ' << s2;
  return 0;
}