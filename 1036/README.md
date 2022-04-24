# 1036 Boys vs Girls
This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

### Input Specification:

Each input file contains one test case. Each case contains a positive integer $$N$$, followed by $$N$$ lines of student information. Each line contains a student's `name`, `gender`, `ID` and `grade`, separated by a space, where `name` and `ID` are strings of no more than 10 characters with no space, `gender` is either `F` (female) or `M` (male), and `grade` is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

### Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference $$grade_F-grade_M$$. If one such kind of student is missing, output `Absent` in the corresponding line, and output `NA` in the third line instead.

### Sample Input 1:
```in
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
```

### Sample Output 1:
```out
Mary EE990830
Joe Math990112
6
```

### Sample Input 2:
```in
1
Jean M AA980920 60
```

### Sample Output 2:
```out
Absent
Jean AA980920
NA
```

```cpp
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
```