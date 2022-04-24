# 1126 Eulerian Path
In graph theory, an Eulerian path is a path in a graph which visits every edge exactly once. Similarly, an Eulerian circuit is an Eulerian path which starts and ends on the same vertex. They were first discussed by Leonhard Euler while solving the famous Seven Bridges of Konigsberg problem in 1736. It has been proven that connected graphs with all vertices of even degree have an Eulerian circuit, and such graphs are called **Eulerian**. If there are exactly two vertices of odd degree, all Eulerian paths start at one of them and end at the other. A graph that has an Eulerian path but not an Eulerian circuit is called **semi-Eulerian**. (Cited from https://en.wikipedia.org/wiki/Eulerian_path)

Given an undirected graph, you are supposed to tell if it is Eulerian, semi-Eulerian, or non-Eulerian.

### Input Specification:

Each input file contains one test case. Each case starts with a line containing 2 numbers N ($$\le$$ 500), and M, which are the total number of vertices, and the number of edges, respectively. Then M lines follow, each describes an edge by giving the two ends of the edge (the vertices are numbered from 1 to N).

### Output Specification:

For each test case, first print in a line the degrees of the vertices in ascending order of their indices. Then in the next line print your conclusion about the graph -- either `Eulerian`, `Semi-Eulerian`, or `Non-Eulerian`. Note that all the numbers in the first line must be separated by exactly 1 space, and there must be no extra space at the beginning or the end of the line.

### Sample Input 1:
```in
7 12
5 7
1 2
1 3
2 3
2 4
3 4
5 2
7 6
6 3
4 5
6 4
5 6
```

### Sample Output 1:
```out
2 4 4 4 4 4 2
Eulerian
```

### Sample Input 2:
```in
6 10
1 2
1 3
2 3
2 4
3 4
5 2
6 3
4 5
6 4
5 6
```

### Sample Output 2:
```out
2 4 4 4 3 3
Semi-Eulerian
```

### Sample Input 3:
```in
5 8
1 2
2 5
5 4
4 1
1 3
3 2
3 4
5 3
```

### Sample Output 3:
```out
3 3 4 3 3
Non-Eulerian
```

```cpp
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool dfs(vector<vector<bool>>& edge, int root) {
	static vector<bool> visited(edge.size());
	static int cnt = 0;
	cnt++;
	visited[root] = true;
	bool flag = cnt == edge.size() ? true : false;
	for (int i = 0; i < edge.size(); i++) {
		if (!visited[i] && edge[root][i]) {
			flag = dfs(edge, i) || flag;
		}
	}
	return flag;
}

int main() {
	int n, m, evendig = 0;
	cin >> n >> m;
	vector<vector<bool>> edge(n, vector<bool>(n));
	vector<int> indigree(n);
	for (int i = 0, x, y; i < m; i++) {
		scanf("%d %d", &x, &y);
		edge[x][y] = edge[--y][--x] = true;
		indigree[x]++;
		indigree[y]++;
	}
	for (int i = 0; i < n; i++) {
		if (i) putchar(' ');
		if (indigree[i] % 2 == 0) evendig++;
		printf("%d", indigree[i]);
	}
	cout << endl;
	if (dfs(edge, 0)) {
		if (evendig == n) {
			cout << "Eulerian" << endl;
		}
		else if (evendig == n - 2) {
			cout << "Semi-Eulerian" << endl;
		}
		else
			cout << "Non-Eulerian" << endl;
	}
	else {
		cout << "Non-Eulerian" << endl;
	}
	return 0;
}
```