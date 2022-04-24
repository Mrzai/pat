#include <iostream>
#include <string>
using namespace std;

int main() {
  char num[][5] = {"ling", "yi",  "er", "san", "si",
                   "wu",   "liu", "qi", "ba",  "jiu"};
  char decimal[][5] = {"Fu", "Qian", "Wan", "Shi", "Bai", "Yi"};
  string s;
  cin >> s;
  int i = 0;
  if (s[0] == '-') printf(decimal[i++]);
  if (s[0] == '0') {
    printf(num[0]);
    return 0;
  }
  for (; i < s.size(); i++) {
    int j = s.size() - i;

    if (s[i] != '0') {
      if (i) putchar(' ');
      printf("%s", num[s[i] - '0']);
    } else if (i + 1 < s.size() && s[i + 1] != '0') {
      if (i) putchar(' ');
      printf("%s", num[0]);
      continue;
    } else if (j % 4 != 1)
      continue;
    if (j % 4 != 1)
      printf(" %s", decimal[j % 4 + 1]);
    else if (j == 5)
      printf(" %s", decimal[2]);
    else if (j == 9)
      printf(" %s", decimal[5]);
  }
  return 0;
}