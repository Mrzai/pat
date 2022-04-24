# 1063 Set Similarity
Given two sets of integers, the similarity of the sets is defined to be $$N_c/N_t\times 100\%$$, where $$N_c$$ is the number of distinct common numbers shared by the two sets, and $$N_t$$ is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

### Input Specification:

Each input file contains one test case. Each case first gives a positive integer $$N$$ ($$\le 50$$) which is the total number of sets. Then $$N$$ lines follow, each gives a set with a positive $$M$$ ($$\le 10^4$$) and followed by $$M$$ integers in the range [$$0, 10^9$$]. After the input of sets, a positive integer $$K$$ ($$\le 2000$$) is given, followed by $$K$$ lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to $$N$$). All the numbers in a line are separated by a space.

### Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

### Sample Input:
```in
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
```

### Sample Output:
```out
50.0%
33.3%
```


```cpp
#include <cstdio>
#include <set>
using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	set<int> s[51];
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int temp;
			scanf("%d", &temp);
			s[i].insert(temp);
		}
	}
	int q_times;
	scanf("%d", &q_times);
	for (int k = 0; k < q_times; k++) {
		int i, j;
		float cnt = 0;
		scanf("%d %d", &i, &j);
		for (auto it = s[i].begin(); it != s[i].end(); it++) {
			if (s[j].count(*it)) cnt++;
		}
		printf("%.1f%%\n", cnt / (s[i].size() + s[j].size() - cnt) * 100);
		
	}
	return 0;
}
```