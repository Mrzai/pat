#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct station {
  float price;
  float dis;
};

bool cmp(station a, station b) { return a.dis < b.dis; }
int main() {
  float c, d1, d2, cost = 0, c_temp = 0;
  int n;
  cin >> c >> d1 >> d2 >> n;
  vector<station> s(n + 1);
  for (int i = 0; i < n; i++) {
    scanf("%f %f", &s[i].price, &s[i].dis);
  }
  s[n].dis = d1;
  s[n].price = 0;
  sort(s.begin(), s.end(), cmp);
  if (s[0].dis != 0) {
    printf("The maximum travel distance = 0.00");
    return 0;
  }
  for (int i = 0; i < n;) {
    if (s[i + 1].dis - s[i].dis > c * d2) {
      printf("The maximum travel distance = %.2f", s[i].dis + c * d2);
      return 0;
    }
    int min = 1, flag = 0;
    float min_price = s[i + 1].price;
    for (int j = 1; s[i + j].dis - s[i].dis <= c * d2 && (i + j) <= n; j++) {
      if (s[i + j].price <= s[i].price) {
        flag = j;
        break;
      }

      if (s[i + j].price < min_price) {
        min = j;
        min_price = s[i + j].price;
      }
    }
    if (flag) {
      float dis_temp = s[i + flag].dis - s[i].dis;
      cost += s[i].price * (dis_temp / d2 - c_temp);
      c_temp = 0;
      i += flag;
    } else {
      float dis_temp = s[i + min].dis - s[i].dis;
      cost += s[i].price * (c - c_temp);
      c_temp = c - dis_temp / d2;
      i += min;
    }
  }
  printf("%.2f", cost);
  return 0;
}
