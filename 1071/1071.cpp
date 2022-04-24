#include <cctype>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  string s, temp, max_word;
  map<string, int> m;
  getline(cin, s);
  for (int i = 0; i < s.size(); i++) {
    if (!isalnum(s[i])) continue;
    while (isalnum(s[i]) && i < s.size()) {
      if (isupper(s[i])) s[i] = tolower(s[i]);
      temp += s[i++];
    }
    m[temp]++;
    temp.clear();
  }
  int max = 0;
  for (auto it : m) {
    if (it.second > max) {
      max_word = it.first;
      max = it.second;
    }
  }
  cout << max_word << ' ' << max;
  return 0;
}