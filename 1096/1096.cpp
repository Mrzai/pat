#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int num, k;
  vector<int> v;
  vector<int> temp;
  cin >> num;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      k = i;
      temp.push_back(i);
      for (int j = i + 1; num % (k * j) == 0; j++) {
        temp.push_back(j);
        k *= j;
      }
      if (temp.size() > v.size()) v.swap(temp);
      temp.resize(0);
    }
  }
  if (v.size() == 0) {
    cout << 1 << endl << num;
    return 0;
  }
  cout << v.size() << endl;
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    if (it == v.begin())
      cout << *it;
    else
      cout << '*' << *it;
  }
  return 0;
}