#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int max_len = 0;
  string s;
  getline(cin, s);
  int end = s.size();
  for (int i = 0; i < end; i++) {
    int len = end - i;
    for (int j = end - 1, k = i, temp = end - 1; j > k;) {
      if (s[j] == s[k]) {
        k++;
        j--;
      } else {
        j = temp - 1;
        temp--;
        k = i;
        len = j - k + 1;
      }
    }
    max_len = len > max_len ? len : max_len;
  }
  cout << max_len;
}