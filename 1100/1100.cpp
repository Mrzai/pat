#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  string s[25] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                  "jly",  "aug", "sep", "oct", "nov", "dec", "tam",
                  "hel",  "maa", "huh", "tou", "kes", "hei", "elo",
                  "syy",  "lok", "mer", "jou"};
  map<string, int> m;
  for (int i = 0; i < 13; i++) {
    m[s[i]] = i;
  }
  for (int i = 13; i < 25; i++) {
    m[s[i]] = (i - 12) * 13;
  }

  int num;
  cin >> num;
  getchar();
  while (num--) {
    string in;
    getline(cin, in);
    if (in.length() > 4) {
      string str1 = in.substr(0, 3);
      string str2 = in.substr(4);
      cout << m[str1] + m[str2] << endl;
    } else if (in[0] <= '9' && in[0] >= '0') {
      int num = 0;
      for (auto it = in.begin(); it != in.end(); it++) {
        num = num * 10 + *it - '0';
      }
      if ((num / 13) && (num % 13))
        cout << s[num / 13 + 12] << ' ' << s[num % 13] << endl;
      else if (num / 13)
        cout << s[num / 13 + 12] << endl;
      else
        cout << s[num % 13] << endl;
    } else
      cout << m[in] << endl;
  }
  return 0;
}