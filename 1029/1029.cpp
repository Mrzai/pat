#include <iostream>
#define maxsize 200010
using namespace std;
int s1[maxsize] = {0};
int main() {
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d", s1 + i);
  }
  int cnt = 0, i = 0, n, temp, k;
  cin >> n;
  k = (m + n + 1) / 2;
  while (n--) {
    scanf("%d", &temp);
    while (i < m && s1[i] < temp) {
      cnt++;
      if (cnt == k) {
        cout << s1[i];
        return 0;
      }
      i++;
    }
    cnt++;
    if (cnt == k) {
      cout << temp;
      return 0;
    }
  }
  while (i < m) {
    cnt++;
    if (cnt == k) {
      cout << s1[i];
      return 0;
    }
    i++;
  }
}