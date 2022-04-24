#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int nc, np;
  cin >> nc;
  vector<int> vc(nc);
  for (int i = 0; i < nc; i++) {
    scanf("%d", &vc[i]);
  }
  sort(vc.begin(), vc.end());
  cin >> np;
  vector<int> vp(np);
  for (int i = 0; i < np; i++) {
    scanf("%d", &vp[i]);
  }
  sort(vp.begin(), vp.end());

  long long sum = 0;
  for (int i = nc - 1, j = np - 1; vc[i] > 0 && vp[j] > 0; i--, j--) {
    sum += vc[i] * vp[j];
  }
  for (int i = 0, j = 0; vc[i] < 0 && vp[j] < 0; i++, j++) {
    sum += vc[i] * vp[j];
  }
  cout << sum << endl;
}