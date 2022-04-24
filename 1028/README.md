# 1028 List Sorting
Excel can sort records according to any column. Now you are supposed to imitate this function.

### Input Specification:

Each input file contains one test case. For each case, the first line contains two integers $$N$$ ($$\le 10^5$$) and $$C$$, where $$N$$ is the number of records and $$C$$ is the column that you are supposed to sort the records with. Then $$N$$ lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).

### Output Specification:

For each test case, output the sorting result in $$N$$ lines. That is, if $$C$$ = 1 then the records must be sorted in increasing order according to ID's; if $$C$$ = 2 then the records must be sorted in non-decreasing order according to names; and if $$C$$ = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.

### Sample Input 1:
```in
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60

```

### Sample Output 1:
```out
000001 Zoe 60
000007 James 85
000010 Amy 90

```

### Sample Input 2:
```in
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98

```

### Sample Output 2:
```out
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60

```

### Sample Input 3:
```in
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 9

```

### Sample Output 3:
```out
000002 James 9
000001 Zoe 60
000007 James 85
000010 Amy 90

```

**鸣谢用户 wangzhj 补充数据！**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
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



```