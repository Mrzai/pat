# 1120 Friend Numbers
Two integers are called "friend numbers" if they share the same sum of their digits, and the sum is their "friend ID". For example, 123 and 51 are friend numbers since 1+2+3 = 5+1 = 6, and 6 is their friend ID. Given some numbers, you are supposed to count the number of different friend ID's among them.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N. Then N positive integers are given in the next line, separated by spaces. All the numbers are less than $$10^4$$.

### Output Specification:

For each case, print in the first line the number of different friend ID's among the given integers. Then in the second line, output the friend ID's in increasing order. The numbers must be separated by exactly one space and there must be no extra space at the end of the line.

### Sample Input:
```in
8
123 899 51 998 27 33 36 12
```

### Sample Output:
```out
4
3 6 9 26
```

```cpp
#include <iostream>
#include <vector>
#define maxsize 40
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	vector<int> cnt(maxsize);
	vector<int> out;
	int n;
	cin >> n;
	for (int i = 0, integer; i < n; i++) {
		int temp = 0;
		cin >> integer;
		while (integer > 0) {
			temp += integer % 10;
			integer /= 10;
		}
		cnt[temp]++;
	}
	for (int i = 0; i < maxsize; i++) {
		if (cnt[i]) {
			out.push_back(i);
		}
	}
	cout << out.size() << endl;
	auto it = out.begin();
	cout << *it++;
	while (it != out.end()) cout << ' ' << *it++;
	return 0;
}
```