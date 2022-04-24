#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  v.resize(501);
  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    v[temp]++;
  }
  for (int i = 1; i <= 500; i++) {
    if (v[i]) {
      v[i]--;
      if (m > i && m - i <= 500 && v[m - i]) {
        cout << i << ' ' << m - i;
        return 0;
      }
      v[i]++;
    }
  }
  cout << "No Solution" << endl;
  return 0;
}