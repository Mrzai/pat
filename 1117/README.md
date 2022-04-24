# 1117 Eddington Number
British astronomer Eddington liked to ride a bike. It is said that in order to show off his skill, he has even defined an "Eddington number", $$E$$ -- that is, the maximum integer $$E$$ such that it is for $$E$$ days that one rides more than $$E$$ miles. Eddington's own $$E$$ was 87.

Now given everyday's distances that one rides for $$N$$ days, you are supposed to find the corresponding $$E$$ ($$\le N$$).

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer $$N$$ ($$\le 10^5$$), the days of continuous riding. Then $$N$$ non-negative integers are given in the next line, being the riding distances of everyday.

### Output Specification:

For each case, print in a line the Eddington number for these $$N$$ days.

### Sample Input:
```in
10
6 7 6 9 3 10 8 2 7 8
```

### Sample Output:
```out
6
```

```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, e = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end(), greater<int>());
	while (e < n && v[e] > e + 1) e++;
	cout << e << endl;
	return 0;
}
```