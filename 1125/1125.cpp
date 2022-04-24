#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i < n; i++) {
    v[0] = (v[i] + v[0]) / 2;
  }
  printf("%d", v[0]);
  return 0;
}