#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct record {
  char name[10];
  int age;
  int net_worth;
};

bool cmp(record a, record b) {
  if (a.net_worth != b.net_worth)
    return a.net_worth > b.net_worth;
  else if (a.age != b.age)
    return a.age < b.age;
  else
    return strcmp(a.name, b.name) < 0;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<struct record> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%s %d %d", &v[i].name, &v[i].age, &v[i].net_worth);
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < k; i++) {
    int m, amin, amax, p = 0, q;
    scanf("%d %d %d", &m, &amin, &amax);
    vector<record> temp;
    printf("Case #%d:\n", i + 1);
    for (int j = 0, count = 0; j < v.size() && count < m; j++) {
      if (v[j].age >= amin && v[j].age <= amax) {
        temp.push_back(v[j]);
        count++;
      }
    }
    if (temp.empty()) {
      printf("None\n");
      continue;
    }
    for (int j = 0; j < temp.size(); j++) {
      printf("%s %d %d\n", temp[j].name, temp[j].age, temp[j].net_worth);
    }
  }
  return 0;
}