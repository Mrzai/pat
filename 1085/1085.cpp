#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, maxlen = 0;
  long long p;
  cin >> n >> p;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n && n - i > maxlen; i++) {
    int low = i, high = n - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (v[mid] > v[i] * p)
        high = mid - 1;
      else
        low = mid + 1;
    }
    maxlen = max(maxlen, low - i);
  }
  cout << maxlen;
  return 0;
}