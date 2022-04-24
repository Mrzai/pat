#include <cmath>
#include <iostream>
#include <string>
using namespace std;

bool isPrime(int num) {
  if (num == 0 || num == 1) return false;
  for (int i = 2; i <= sqrt(num); i++)
    if (num % i == 0) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  int l, k;
  string number, kdprime = "404";
  cin >> l >> k >> number;
  for (int i = 0; i <= l - k; i++) {
    if (isPrime(stoi(number.substr(i, k)))) {
      kdprime = number.substr(i, k);
      break;
    }
  }
  cout << kdprime << endl;
  return 0;
}