#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define maxsize 100000
using namespace std;

struct customer {
  int time;
  int p_time;
} c[maxsize];
bool cmp(customer a, customer b) { return a.time < b.time; }
int main() {
  int n, k, num = 0;
  float count = 0;
  cin >> n >> k;
  int e_time = 8 * 3600;
  int l_time = 17 * 3600;
  for (int i = 0; i < n; i++) {
    int h, m, s;
    scanf("%d:%d:%d %d", &h, &m, &s, &c[i].p_time);
    c[i].time = h * 3600 + m * 60 + s;
    if (c[i].time <= l_time) num++;
    c[i].p_time *= 60;
  }
  sort(c, c + n, cmp);
  vector<int> v(k, e_time);
  for (int i = 0; i < n; i++) {
    if (c[i].time < l_time) {
      if (v[0] > c[i].time) {
        count += (v[0] - c[i].time);
        v[0] += c[i].p_time;
      } else
        v[0] = c[i].time + c[i].p_time;
    }
    sort(v.begin(), v.end());
  }
  if (!num)
    printf("0.0");
  else
    printf("%.1f", count / (60 * num));
  return 0;
}