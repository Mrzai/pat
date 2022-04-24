#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, e = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v.begin(), v.end(), greater<int>());
  while (e < n && v[e] > e + 1) e++;
  cout << e << endl;
  return 0;
}