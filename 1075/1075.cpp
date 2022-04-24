#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct record {
  bool pass = false;
  int id;
  int grade[6] = {0};
  int sum = 0;
};

bool cmp(record a, record b) {
  if (a.sum != b.sum)
    return a.sum > b.sum;
  else if (a.grade[0] != b.grade[0])
    return a.grade[0] > b.grade[0];
  else
    return a.id < b.id;
}

int main() {
  int n, k, m, id, index, score, p[6] = {0};
  cin >> n >> k >> m;
  vector<record> v(n + 1);
  for (int i = 1; i <= k; i++) {
    scanf("%d", p + i);
  }
  for (int i = 1; i <= n; i++) {
    fill(v[i].grade + 1, v[i].grade + 6, -1);
    v[i].id = i;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &id, &index, &score);
    v[id].grade[index] = max(score, v[id].grade[index]);
    if (score != -1) {
      v[id].pass = true;
    } else if (v[id].grade[index] == -1)
      v[id].grade[index] = -2;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (v[i].grade[j] == p[j]) v[i].grade[0]++;
      if (v[i].grade[j] != -2 && v[i].grade[j] != -1) v[i].sum += v[i].grade[j];
    }
  }

  sort(v.begin() + 1, v.end(), cmp);
  for (int i = 1, temp = 0; i < v.size(); i++) {
    if (!v[i].pass) continue;
    if (v[i].sum == v[temp].sum) {
      printf("%d %05d %d", temp, v[i].id, v[i].sum);
    } else {
      temp = i;
      printf("%d %05d %d", i, v[i].id, v[i].sum);
    }
    for (int j = 1; j <= k; j++) {
      if (v[i].grade[j] == -1)
        printf(" -");
      else if (v[i].grade[j] == -2)
        printf(" 0");
      else
        printf(" %d", v[i].grade[j]);
    }
    putchar('\n');
  }
  return 0;
}