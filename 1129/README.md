# 1129 Recommendation System
Recommendation system predicts the preference that a user would give to an item. Now you are asked to program a very simple recommendation system that rates the user's preference by the number of times that an item has been accessed by this user.

### Input Specification:

Each input file contains one test case. For each test case, the first line contains two positive integers: N ($$\le$$ 50,000), the total number of queries, and K ($$\le$$ 10), the maximum number of recommendations the system must show to the user. Then given in the second line are the indices of items that the user is accessing -- for the sake of simplicity, all the items are indexed from 1 to N. All the numbers in a line are separated by a space.


### Output Specification:

For each case, process the queries one by one. Output the recommendations for each query in a line in the format:
```
query: rec[1] rec[2] ... rec[K]
```
where `query` is the item that the user is accessing, and `rec[i]` (`i`=1, ... K) is the `i`-th item that the system recommends to the user. The first K items that have been accessed most frequently are supposed to be recommended in non-increasing order of their frequencies. If there is a tie, the items will be ordered by their indices in increasing order.

Note: there is no output for the first item since it is impossible to give any recommendation at the time. It is guaranteed to have the output for at least one query.

### Sample Input:
```in
12 3
3 5 7 5 5 3 2 1 8 3 8 12
```

### Sample Output:
```out
5: 3
7: 3 5
5: 3 5 7
5: 5 3 7
3: 5 3 7
2: 5 3 7
1: 5 3 2
8: 5 3 1
3: 5 3 1
8: 3 5 1
12: 3 5 8
```

```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define maxsize 50010
using namespace std;

struct node{
	int value, times;
	bool operator < (const node& b) const {
		if (times != b.times)
			return times > b.times;
		else
			return value < b.value;
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> times(maxsize);
	set<node> s;
	for (int i = 0, temp; i < n; i++) {
		scanf("%d", &temp);
		if (i) {
			int cnt = 0;
			printf("%d: ", temp);
			for (auto it = s.begin(); cnt < k && it != s.end(); cnt++, it++) {
				if (cnt) putchar(' ');
				printf("%d", it->value);
			}
			putchar('\n');
		}
		auto it = s.find({ temp, times[temp] });
		if (it != s.end()) s.erase(it);
		times[temp]++;
		s.insert({ temp, times[temp] });
	}
	return 0;
}
```