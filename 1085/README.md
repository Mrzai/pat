# 1085 Perfect Sequence
Given a sequence of positive integers and another positive integer $$p$$.  The sequence is said to be a **perfect sequence** if $$M \le m \times p$$ where $$M$$ and $$m$$ are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter $$p$$, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

### Input Specification:

Each input file contains one test case.  For each case, the first line contains two positive integers $$N$$ and $$p$$, where $$N$$ ($$\le 10^5$$) is the number of integers in the sequence, and $$p$$ ($$\le 10^9$$) is the parameter.  In the second line there are $$N$$ positive integers, each is no greater than $$10^9$$.

### Output Specification:

For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

### Sample Input:
```in
10 8
2 3 20 4 5 1 6 7 8 9
```

### Sample Output:
```out
8
```

```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, maxlen = 0;
    long long p;
	cin >> n >> p;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n && n - i > maxlen; i++) {
		int low = i, high = n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (v[mid] > v[i] * p)
				high = mid - 1;
			else
				low = mid + 1;
		}
		maxlen = max(maxlen, low - i);
	}
	cout << maxlen;
	return 0;
}
```