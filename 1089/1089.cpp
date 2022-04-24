#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int num;

int main() {
  int i, j;
  vector<int> v, t;
  cin >> num;
  v.resize(num + 2);
  t.resize(num + 2);
  for (i = 1; i <= num; i++) {
    scanf("%d", &v[i]);
  }
  for (i = 1; i <= num; i++) {
    scanf("%d", &t[i]);
  }
  for (i = 1; i < num && t[i] <= t[i + 1]; i++)
    ;
  for (j = i + 1; j <= num && v[j] == t[j]; j++)
    ;
  if (j == num + 1) {
    cout << "Insertion Sort" << endl;
    sort(&v[1], &v[i + 2]);
  } else {
    bool flag = false;
    cout << "Merge Sort" << endl;
    for (i = 1; !flag; i *= 2) {
      if (t == v) flag = true;
      int k = 1;
      for (; k + 2 * i <= num; k += 2 * i) sort(&v[k], &v[k + 2 * i]);
      sort(&v[k], &v[num + 1]);
    }
  }
  for (int i = 1; i <= num; i++) {
    if (i - 1) putchar(' ');
    printf("%d", v[i]);
  }
  return 0;
}