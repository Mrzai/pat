#include <iostream>
using namespace std;
#define max 1000000007

int main() {
  string s;
  int t = 0, a = 0;
  long long cnt = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'T')
      t++;
    else if (s[i] == 'A')
      a++;
  }
  int pb = 0, ta = t;
  for (int i = 0; a > 0; i++) {
    if (s[i] == 'A') {
      long long temp = pb * ta;
      cnt = (cnt + temp) % max;
      a--;
    } else if (s[i] == 'P') {
      pb++;
    } else
      ta--;
  }
  cout << cnt;
  return 0;
}