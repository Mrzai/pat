#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct stu {
  string name;
  string id;
  int grade;
};
bool cmp(stu a, stu b) { return a.grade > b.grade; }
int main() {
  vector<stu> v;
  int num, grade;
  string name, id;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> name >> id >> grade;
    v.push_back({name, id, grade});
  }
  int grade1, grade2;
  bool flag = false;
  cin >> grade1 >> grade2;
  sort(v.begin(), v.end(), cmp);
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it->grade >= grade1 && it->grade <= grade2) {
      flag = true;
      cout << it->name << ' ' << it->id << endl;
    }
  }
  if (!flag) cout << "NONE";
  return 0;
}
