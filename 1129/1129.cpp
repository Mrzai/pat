#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#define maxsize 50010
using namespace std;

struct node {
  int value, times;
  bool operator<(const node& b) const {
    if (times != b.times)
      return times > b.times;
    else
      return value < b.value;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> times(maxsize);
  set<node> s;
  for (int i = 0, temp; i < n; i++) {
    scanf("%d", &temp);
    if (i) {
      int cnt = 0;
      printf("%d: ", temp);
      for (auto it = s.begin(); cnt < k && it != s.end(); cnt++, it++) {
        if (cnt) putchar(' ');
        printf("%d", it->value);
      }
      putchar('\n');
    }
    auto it = s.find({temp, times[temp]});
    if (it != s.end()) s.erase(it);
    times[temp]++;
    s.insert({temp, times[temp]});
  }
  return 0;
}