#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
  int h;
  string name;
};

bool cmp(node a, node b) { return a.h != b.h ? a.h > b.h : a.name < b.name; }

int main() {
  ios::sync_with_stdio(false);
  int n, k, len;
  cin >> n >> k;
  vector<node> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].name >> v[i].h;
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0, j = 0; i < k; i++) {
    if (i == 0)
      len = n / k + n % k;
    else
      len = n / k;
    int cnt = 0, m = len / 2;
    vector<int> temp(len);
    bool flag = true;
    while (cnt < len) {
      if (flag) {
        m += cnt;
        // cout << m << ' ' << j << endl;
        temp[m] = j++;
      } else {
        m -= cnt;
        // cout << m << ' ' << j << endl;
        temp[m] = j++;
      }
      cnt++;
      flag = !flag;
    }
    for (int i = 0; i < len; i++) {
      if (i) cout << ' ';
      cout << v[temp[i]].name;
    }
    cout << endl;
  }
  return 0;
}