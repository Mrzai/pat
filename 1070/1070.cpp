#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
struct cake {
  float a, b;
} c[1000];
bool cmp(cake x, cake y) { return x.b / x.a > y.b / y.a; }
int main() {
  int num;
  float demand, cnt = 0.0, profit = 0.0;
  cin >> num >> demand;
  for (int i = 0; i < num; i++) {
    scanf("%f", &c[i].a);
  }
  for (int i = 0; i < num; i++) {
    scanf("%f", &c[i].b);
  }
  sort(c, c + num, cmp);
  for (int i = 0; i < num && cnt < demand; i++) {
    if (demand - cnt >= c[i].a) {
      cnt += c[i].a;
      profit += c[i].b;
    } else {
      profit += ((demand - cnt) / c[i].a * c[i].b);
      cnt = demand;
    }
  }
  printf("%.2f", profit);
  return 0;
}