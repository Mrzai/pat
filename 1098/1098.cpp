#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void adjustheap(vector<int> &v, int k, int len) {
  int temp = v[k];
  for (int i = k * 2 + 1; i < len; i = i * 2 + 1) {
    if (i + 1 < len && v[i + 1] > v[i]) i++;
    if (temp >= v[i])
      break;
    else {
      v[k] = v[i];
      k = i;
    }
  }
  v[k] = temp;
}

void buildheap(vector<int> &v, int len) {
  for (int i = len / 2 - 1; i >= 0; i--) {
    adjustheap(v, i, len);
  }
}

int main() {
  ios::sync_with_stdio(false);
  int i, j, n;
  cin >> n;
  vector<int> v(n + 1), t(n + 1);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (i = 0; i < n - 1 && t[i] <= t[i + 1]; i++)
    ;
  for (j = i + 1; j < n && v[j] == t[j]; j++)
    ;
  if (j == n) {
    cout << "Insertion Sort" << endl;
    sort(&v[0], &v[i + 2]);
  } else {
    cout << "Heap Sort" << endl;
    bool flag = true;
    buildheap(v, n);
    for (i = n; flag; i--) {
      if (v == t) flag = false;
      swap(v[0], v[i - 1]);
      adjustheap(v, 0, i - 1);
    }
  }
  for (i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << v[i];
  }
  return 0;
}