# 1122 Hamiltonian Cycle
The "Hamilton cycle problem" is to find a simple cycle that contains every vertex in a graph. Such a cycle is called a "Hamiltonian cycle".

In this problem, you are supposed to tell if a given cycle is a Hamiltonian cycle.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers $$N$$ ($$2< N \le 200$$), the number of vertices, and $$M$$, the number of edges in an undirected graph. Then $$M$$ lines follow, each describes an edge in the format `Vertex1 Vertex2`, where the vertices are numbered from 1 to $$N$$. The next line gives a positive integer $$K$$ which is the number of queries, followed by $$K$$ lines of queries, each in the format:

$$n$$ $$V_1$$ $$V_2$$ ... $$V_n$$

where $$n$$ is the number of vertices in the list, and $$V_i$$'s are the vertices on a path.

### Output Specification:

For each query, print in a line `YES` if the path does form a Hamiltonian cycle, or `NO` if not.

### Sample Input:
```in
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1
```

### Sample Output:
```out
YES
NO
NO
NO
YES
NO
```

```cpp
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m;
	vector<int> temp;
	vector<vector<bool>> edge(n + 1, vector<bool>(n + 1, false));
	for (int i = 0, x, y; i < m; i++) {
		scanf("%d %d", &x, &y);
		edge[x][y] = edge[y][x] = true;
	}
	cin >> k;
	while (k--) {
		int num;
		cin >> num;
		vector<int> v(num);
		set<int> s;
		for (int i = 0; i < num; i++) {
			scanf("%d", &v[i]);
			s.insert(v[i]);
		}
		bool flag = true;
		if (s.size() != n || num - 1 != n || v[0] != v[num - 1]) {
			flag = false;
		}
		else {
			for (int i = 0; i < num - 1; i++) {
				if (!edge[v[i]][v[i + 1]]) {
					flag = false;
					break;
				}
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}
```