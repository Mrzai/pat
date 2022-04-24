#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
  if (n == 1 || n == 0) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 2, ntemp = n; i <= ntemp; i++) {
    if (isPrime(i)) {
      while (ntemp % i == 0) {
        v.push_back(i);
        ntemp /= i;
      }
    }
  }
  cout << n << '=';
  if (n == 1) cout << 1;
  for (int i = 0, cnt = 1, flag = 0; i < v.size(); i++) {
    if (i + 1 < v.size() && v[i + 1] == v[i])
      cnt++;
    else {
      if (flag++) cout << '*';
      if (cnt != 1)
        cout << v[i] << '^' << cnt;
      else
        cout << v[i];
      cnt = 1;
    }
  }
  return 0;
}