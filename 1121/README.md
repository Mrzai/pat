# 1121 Damn Single
"Damn Single (单身狗)" is the Chinese nickname for someone who is being single. You are supposed to find those who are alone in a big party, so they can be taken care of.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N ($$\le$$ 50,000), the total number of couples. Then N lines of the couples follow, each gives a couple of ID's which are 5-digit numbers (i.e. from 00000 to 99999). After the list of couples, there is a positive integer M ($$\le$$ 10,000) followed by M ID's of the party guests. The numbers are separated by spaces. It is guaranteed that nobody is having bigamous marriage (重婚) or dangling with more than one companion.

### Output Specification:

First print in a line the total number of lonely guests. Then in the next line, print their ID's in increasing order. The numbers must be separated by exactly 1 space, and there must be no extra space at the end of the line.

### Sample Input:
```in
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
```

### Sample Output:
```out
5
10000 23333 44444 55555 88888
```

```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define maxsize 1000000
using namespace std;
bool visited[maxsize] = { false };
vector<int> m(maxsize, -1);

int main() {
	int N, M, cnt = 0;
	cin >> N;
	for (int i = 0, couplea, coupleb; i < N; i++) {
		scanf("%d %d", &couplea, &coupleb);
		m[couplea] = coupleb;
		m[coupleb] = couplea;
	}
	cin >> M;
	vector<int> v(M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &v[i]);
		visited[v[i]] = true;
	}

	for (int i = 0; i < M; i++) {
		if (m[v[i]] != -1 && visited[m[v[i]]]) {
			visited[v[i]] = false;
			visited[m[v[i]]] = false;
			cnt += 2;
		}
	}
	sort(v.begin(), v.end());
	cout << M - cnt << endl;
	for (int i = 0, cnt = 0; i < M; i++) {
		if (visited[v[i]]) {
			if (cnt++) putchar(' ');
			printf("%05d", v[i]);
		}
	}
	return 0;
}
```