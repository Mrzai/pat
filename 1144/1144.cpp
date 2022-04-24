#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, k = 10;
  cin >> n;
  map<int, int> mp;
  for (int i = 0, temp; i < n; i++) {
    scanf("%d", &temp);
    mp[temp]++;
  }
  while (++k) {
    if (!mp[k]) break;
  }
  cout << k << endl;
  return 0;
}