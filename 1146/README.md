# 1146 Topological Order
This is a problem given in the Graduate Entrance Exam in 2018: Which of the following is NOT a topological order obtained from the given directed graph? Now you are supposed to write a program to test each of the options.

![gre.jpg](~/5d35ed2a-4d19-4f13-bf3f-35ed59cebf05.jpg)

### Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers N ($$\le$$ 1,000), the number of vertices in the graph, and M ($$\le$$ 10,000), the number of directed edges. Then M lines follow, each gives the start and the end vertices of an edge. The vertices are numbered from 1 to N. After the graph, there is another positive integer K ($$\le$$ 100). Then K lines of query follow, each gives a permutation of all the vertices. All the numbers in a line are separated by a space.

### Output Specification:

Print in a line all the indices of queries which correspond to "NOT a topological order".  The indices start from zero.  All the numbers are separated by a space, and there must no extra space at the beginning or the end of the line.  It is graranteed that there is at least one answer.

### Sample Input:
```in
6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
6
5 2 3 6 4 1
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6

```

### Sample Output:
```out
0 4 5

```

**鸣谢用户柳汀洲补充数据！**
```cpp
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m;
  vector<int> ntopo;
  vector<int> indgree(n + 1);
  vector<vector<bool>> edge(n + 1, vector<bool>(n + 1));
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    indgree[y]++;
    edge[x][y] = 1;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    bool flag = false;
    vector<int> temp = indgree;
    for (int j = 0, index; j < n; j++) {
      scanf("%d", &index);
      if (temp[index]) flag = true;
      if (flag) continue;
      for (int q = 1; q <= n; q++) {
        if (edge[index][q]) temp[q]--;
      }
    }
    if (flag) ntopo.push_back(i);
  }
  for (int i = 0; i < ntopo.size(); i++) {
    if (i) putchar(' ');
    printf("%d", ntopo[i]);
  }
  return 0;
}
```