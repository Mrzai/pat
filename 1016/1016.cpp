#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct record {
  int state;
  string name;
  int time[4];
  int time_;
};

int rate[25], num;

bool cmp(record a, record b) {
  return a.name == b.name ? a.time_ < b.time_ : a.name < b.name;
}

double cost(record n) {
  double total = n.time[1] * rate[24] * 60 + n.time[3] * rate[n.time[2]];
  for (int j = 0; j < n.time[2]; j++) {
    total += rate[j] * 60;
  }
  return total / 100;
}

int main() {
  for (int i = 0; i < 24; i++) {
    scanf("%d", rate + i);
    rate[24] += rate[i];
  }
  scanf("%d", &num);
  vector<record> r(num);
  for (int i = 0; i < num; i++) {
    string temp;
    cin >> r[i].name;
    scanf("%d:%d:%d:%d", r[i].time, r[i].time + 1, r[i].time + 2,
          r[i].time + 3);
    cin >> temp;
    r[i].state = (temp == "on-line") ? 1 : 0;
    r[i].time_ = (r[i].time[1] * 24 + r[i].time[2]) * 60 + r[i].time[3];
  }

  sort(r.begin(), r.end(), cmp);
  map<string, vector<record>> cus;

  for (int i = 1; i < num; i++) {
    if (r[i].name == r[i - 1].name && r[i].state == 0 && r[i - 1].state == 1) {
      cus[r[i].name].push_back(r[i - 1]);
      cus[r[i].name].push_back(r[i]);
    }
  }
  for (auto it = cus.begin(); it != cus.end(); it++) {
    vector<record> temp = it->second;
    cout << it->first;
    printf(" %02d\n", temp[0].time[0]);
    double total = 0;
    for (int i = 1; i < temp.size(); i += 2) {
      double t = cost(temp[i]) - cost(temp[i - 1]);
      printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].time[1],
             temp[i - 1].time[2], temp[i - 1].time[3], temp[i].time[1],
             temp[i].time[2], temp[i].time[3],
             temp[i].time_ - temp[i - 1].time_, t);
      total += t;
    }
    printf("Total amount: $%.2f\n", total);
  }

  return 0;
}
