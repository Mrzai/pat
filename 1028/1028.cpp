#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct record {
  int id;
  string name;
  int grade;
};
int flag;
bool cmp(record a, record b) {
  if (flag == 1)
    return a.id < b.id;
  else if (flag == 2)
    return a.name != b.name ? a.name < b.name : a.id < b.id;
  else
    return a.grade != b.grade ? a.grade < b.grade : a.id < b.id;
}
int main() {
  int num;
  vector<record> v;
  cin >> num >> flag;
  for (int i = 0; i < num; i++) {
    record *temp = new record;
    cin >> temp->id >> temp->name >> temp->grade;
    v.push_back(*temp);
  }
  sort(v.begin(), v.end(), cmp);
  for (auto it = v.begin(); it != v.end(); it++) {
    printf("%06d ", it->id);
    cout << it->name;
    printf(" %d\n", it->grade);
  }
}
