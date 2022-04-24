# 1017 Queueing at Bank
Suppose a bank has $$K$$ windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.

Now given the arriving time $$T$$ and the processing time $$P$$ of each customer, you are supposed to tell the average waiting time of all the customers.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: $$N$$ ($$\le 10^4$$) - the total number of customers, and $$K$$ ($$\le 100$$) - the number of windows. Then $$N$$ lines follow, each contains 2 times: `HH:MM:SS` - the arriving time, and $$P$$ - the processing time in minutes of a customer. Here `HH` is in the range [00, 23], `MM` and `SS` are both in [00, 59]. It is assumed that no two customers arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

### Output Specification:

For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.

### Sample Input:
```in
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
```

### Sample Output:
```out
8.2
```

```cpp
#include <iostream>
#include <cstdio>
#include <vector> 
#include <algorithm>
#define maxsize 100000
using namespace std;

struct customer {
	int time;
	int p_time;
}c[maxsize];
bool cmp(customer a, customer b) { return a.time < b.time; }
int main() {
	int n, k, num = 0;
	float count = 0;
	cin >> n >> k;
	int e_time = 8 * 3600;
	int l_time = 17 * 3600;
	for (int i = 0; i < n; i++) {
		int h, m, s;
		scanf("%d:%d:%d %d", &h, &m, &s, &c[i].p_time);
		c[i].time = h * 3600 + m * 60 + s;
        if(c[i].time <= l_time) num++;
		c[i].p_time *= 60;
	}
	sort(c, c + n, cmp);
	vector<int> v(k, e_time);
	for (int i = 0; i < n; i++) {
		if (c[i].time<l_time) {
			if (v[0] > c[i].time) {
				count += (v[0] - c[i].time);
				v[0] += c[i].p_time;
			}
			else
				v[0] = c[i].time + c[i].p_time;
		}
		sort(v.begin(), v.end());
	}
	if (!num) printf("0.0");
	else printf("%.1f", count / (60 * num));
	return 0;
}
```