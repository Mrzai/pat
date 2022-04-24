#include <iostream>
#include <string>
using namespace std;

int main() {
  int temp[62] = {0}, a = 0, b = 0;
  string str;
  cin >> str;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      temp[str[i] - '0']++;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      temp[str[i] - 'A' + 10]++;
    } else
      temp[str[i] - 'a' + 36]++;
  }

  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      temp[str[i] - '0']--;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      temp[str[i] - 'A' + 10]--;
    } else
      temp[str[i] - 'a' + 36]--;
  }

  for (int i = 0; i < 62; i++) {
    if (temp[i] > 0) a += temp[i];
    if (temp[i] < 0) b -= temp[i];
  }
  if (b) {
    cout << "No " << b << endl;
  } else
    cout << "Yes " << a << endl;
  return 0;
}