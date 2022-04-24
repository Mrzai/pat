#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n), max(n), min(n), pivot;
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    if (!i || v[i] > max[i - 1])
      max[i] = v[i];
    else
      max[i] = max[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1 || v[i] < min[i + 1])
      min[i] = v[i];
    else
      min[i] = min[i + 1];
  }
  for (int i = 0; i < n; i++) {
    if ((i == 0 || max[i - 1] < v[i]) && (i == n - 1 || min[i + 1] > v[i])) {
      pivot.push_back(v[i]);
    }
  }
  cout << pivot.size() << endl;
  for (int i = 0; i < pivot.size(); i++) {
    if (i) putchar(' ');
    printf("%d", pivot[i]);
  }
  cout << endl;
  return 0;
}