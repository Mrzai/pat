#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int num, m, n, k = 0;
  cin >> num;
  vector<int> v(num);

  for (int i = 0; i < num; i++) {
    scanf("%d", &v[i]);
  }
  for (int i = 1, j = num; i <= j; i++, j = num / i) {
    if (i * j == num) {
      m = j;
      n = i;
    }
  }
  vector<vector<int>> temp(m, vector<int>(n));
  bool isplus = true;
  sort(v.begin(), v.end(), greater<int>());
  for (int i = 0, j = -1, x = n, y = m, z = 0, w = 1; k < num;) {
    if (isplus) {
      j++;
      while (j < x) {
        temp[i][j] = v[k++];
        j++;
      }
      j--;
      x--;
      i++;
      while (i < y) {
        temp[i][j] = v[k++];
        i++;
      }
      i--;
      y--;
    } else {
      j--;
      while (j >= z) {
        temp[i][j] = v[k++];
        j--;
      }
      j++;
      z++;
      i--;
      while (i >= w) {
        temp[i][j] = v[k++];
        i--;
      }
      i++;
      w++;
    }
    isplus = !isplus;
  }
  for (int i = 0, j = 0; i < m; i++, j = 0) {
    while (j < n) {
      if (j) putchar(' ');
      printf("%d", temp[i][j]);
      j++;
    }
    putchar('\n');
  }
  return 0;
}