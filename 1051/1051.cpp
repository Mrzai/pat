#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  int m, n, k;
  scanf("%d %d %d", &m, &n, &k);
  for (int i = 0; i < k; i++) {
    stack<int> s;
    bool flag = false;
    int btemp = 0, ntemp;
    for (int j = 0, q = 1; j < n; j++) {
      scanf("%d", &ntemp);
      if (flag) continue;
      if (ntemp > btemp) {
        for (; q <= ntemp; q++) {
          s.push(q);
          if (s.size() > m) {
            flag = true;
            break;
          }
        }
        s.pop();
      } else {
        if (s.empty() || s.top() != ntemp) {
          flag = true;
        }
        s.pop();
      }
      btemp = ntemp;
    }
    if (!flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}