# 1003 Emergency
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

### Input Specification:

Each input file contains one test case. For each test case, the first line contains 4 positive integers: $$N$$ ($$\le 500$$) - the number of cities (and the cities are numbered from 0 to $$N-1$$), $$M$$ - the number of roads, $$C_1$$ and $$C_2$$ - the cities that you are currently in and that you must save, respectively. The next line contains $$N$$ integers, where the $$i$$-th integer is the number of rescue teams in the $$i$$-th city. Then $$M$$ lines follow, each describes a road with three integers $$c_1$$, $$c_2$$ and $$L$$, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from $$C_1$$ to $$C_2$$.

### Output Specification:

For each test case, print in one line two numbers: the number of different shortest paths between $$C_1$$ and $$C_2$$, and the maximum amount of rescue teams you can possibly gather.  All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

### Sample Input:
```in
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
```

### Sample Output:
```out
2 4
```
```cpp
#include <stdio.h>
#define inf 99999
typedef struct {
	int edge[500][500];
}graph;

graph g;
int N,
	M,
	C1,
	C2,
	weight[500] = { 0 },
	res[500] = { 0 },
	num[500] = { 0 };

int dijsktra() {																//处理数据
	int dist[500],
		visited[500] = { 0 };
		
	for (int i = 0;i < N;i++) {
		dist[i] = g.edge[C1][i];
	}
	
	num[C1] = 1;
	weight[C1] = res[C1];

	for (int i = 0; i < N; i++) {
		int u = 0;
		int min = inf;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && dist[j] < min) {
				min = dist[j];
				u = j;
			}
		}
		visited[u] = 1;
		for (int j = 0; j < N;j++) {
			if (!visited[j] && g.edge[u][j] != inf) {
				if (g.edge[u][j] + dist[u] < dist[j]) {
					dist[j] = g.edge[u][j] + dist[u];
					num[j] = num[u];
					weight[j] = weight[u] + res[j];
				}
				else if (g.edge[u][j] + dist[u] == dist[j]) {
					num[j] += num[u];
					if (weight[u] + res[j] > weight[j]) weight[j] = weight[u] + res[j];
				}
			}
		}
	}
	return 0;
}

int main() {																	//处理输入输出
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", res + i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) g.edge[i][j] = 0;
			else g.edge[i][j] = inf;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g.edge[a][b] = c;
		g.edge[b][a] = c;
	}
	
	dijsktra();
	printf("%d %d", num[C2], weight[C2]);
}

```