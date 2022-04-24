#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct stu {
  int id, v, t;
};

bool cmp(stu a, stu b) {
  if (a.t + a.v != b.t + b.v)
    return a.t + a.v > b.t + b.v;
  else if (a.v != b.v)
    return a.v > b.v;
  else
    return a.id < b.id;
}
int main() {
  vector<stu> sages, noblemen, foolmen, others;
  int n, l, h;
  cin >> n >> l >> h;
  for (int i = 0; i < n; i++) {
    int id_temp, v_temp, t_temp;
    scanf("%d %d %d", &id_temp, &v_temp, &t_temp);
    if (v_temp < l || t_temp < l) continue;
    stu temp = {id_temp, v_temp, t_temp};
    if (v_temp >= h && t_temp >= h)
      sages.push_back(temp);
    else if (v_temp >= h && t_temp < h)
      noblemen.push_back(temp);
    else if (v_temp < h && t_temp < h && v_temp >= t_temp)
      foolmen.push_back(temp);
    else
      others.push_back(temp);
  }
  cout << sages.size() + noblemen.size() + foolmen.size() + others.size()
       << endl;

  sort(sages.begin(), sages.end(), cmp);
  for (int i = 0; i < sages.size(); i++) {
    printf("%d %d %d\n", sages[i].id, sages[i].v, sages[i].t);
  }

  sort(noblemen.begin(), noblemen.end(), cmp);
  for (int i = 0; i < noblemen.size(); i++) {
    printf("%d %d %d\n", noblemen[i].id, noblemen[i].v, noblemen[i].t);
  }

  sort(foolmen.begin(), foolmen.end(), cmp);
  for (int i = 0; i < foolmen.size(); i++) {
    printf("%d %d %d\n", foolmen[i].id, foolmen[i].v, foolmen[i].t);
  }

  sort(others.begin(), others.end(), cmp);
  for (int i = 0; i < others.size(); i++) {
    printf("%d %d %d\n", others[i].id, others[i].v, others[i].t);
  }

  return 0;
}