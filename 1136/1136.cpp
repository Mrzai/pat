#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void add(string& a, string& b) {
  int in = 0;
  for (int i = 0, temp; i < a.size(); i++) {
    temp = a[i] - '0';
    a[i] = (a[i] - '0' + b[i] - '0' + in) % 10 + '0';
    in = temp + b[i] - '0' + in >= 10 ? 1 : 0;
  }
  if (in) a += '1';
  b = a;
  reverse(a.begin(), a.end());
}

int main() {
  ios::sync_with_stdio(false);
  int cnt = 0;
  string number, rnumber;
  cin >> number;
  rnumber = number;
  reverse(rnumber.begin(), rnumber.end());
  while (number != rnumber && cnt < 10) {
    cnt++;
    cout << number << " + " << rnumber;
    add(number, rnumber);
    cout << " = " << number << endl;
  }
  if (number == rnumber)
    cout << number << " is a palindromic number." << endl;
  else
    cout << "Not found in 10 iterations." << endl;
  return 0;
}