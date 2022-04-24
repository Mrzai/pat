#include <cstdio>
#include <iostream>
using namespace std;
struct stu {
  string name;
  string id;
  int grade;
  bool flag = false;
};

int main() {
  stu s[2];
  int num;
  cin >> num;
  while (num--) {
    string temp_name;
    char temp_gender;
    string temp_id;
    int temp_grade;
    cin >> temp_name >> temp_gender >> temp_id >> temp_grade;
    if (temp_gender == 'F') {
      if (s[0].flag == false || temp_grade > s[0].grade) {
        s[0].id = temp_id;
        s[0].grade = temp_grade;
        s[0].name = temp_name;
        s[0].flag = true;
      }
    } else {
      if (s[1].flag == false || temp_grade < s[1].grade) {
        s[1].id = temp_id;
        s[1].grade = temp_grade;
        s[1].name = temp_name;
        s[1].flag = true;
      }
    }
  }
  if (!s[0].flag)
    cout << "Absent" << endl;
  else
    cout << s[0].name << " " << s[0].id << endl;
  if (!s[1].flag)
    cout << "Absent" << endl;
  else
    cout << s[1].name << " " << s[1].id << endl;
  if (!s[0].flag || !s[1].flag)
    cout << "NA" << endl;
  else
    cout << s[0].grade - s[1].grade << endl;
  return 0;
}