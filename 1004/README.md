# 1004 Counting Leaves
A family hierarchy is usually presented by a pedigree tree.  Your job is to count those family members who have no child.

### Input Specification:

Each input file contains one test case. Each case starts with a line  containing $$0<N<100$$, the number of nodes in a tree, and $$M$$ ($$<N$$), the number of non-leaf nodes.  Then $$M$$ lines follow, each in the format:
```
ID K ID[1] ID[2] ... ID[K]
```

where `ID` is a two-digit number representing a given non-leaf node, `K` is the number of its children, followed by a sequence of two-digit `ID`'s of its children.  For the sake of simplicity, let us fix the root ID to be `01`.

The input ends with $$N$$ being 0.  That case must NOT be processed.

### Output Specification:

For each test case, you are supposed to count those family members who have no child **for every seniority level** starting from the root.  The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where `01` is the root and `02` is its only child.  Hence on the root `01` level, there is `0` leaf node; and on the next level, there is `1` leaf node.  Then we should output `0 1` in a line.

### Sample Input:
```in
2 1
01 1 02
```

### Sample Output:
```out
0 1
```
```cpp
#include <stdio.h>
#define maxsize 100

typedef struct {
  int edge[maxsize][maxsize] = {0};
} MGrapg;

MGrapg g;
int visited[maxsize] = {0}, queue[maxsize] = {0}, front = 0, rear = 0, m = 0,
    n = 0;

int bfs() {
  int i = 1;
  int flag = 1;
  int d[maxsize] = {0};
  d[0] = 1;
  d[i] = 1;
  int o = 0;
  int count = 0;
  visited[i] = 1;
  queue[rear++] = i;
  while (rear != front) {
    i = queue[front++];
    for (int j = 1; j <= n; j++) {
      if (!g.edge[i][j]) continue;
      if (!visited[j]) {
        flag = 0;
        visited[j] = 1;
        d[j] = d[i] + 1;
        queue[rear++] = j;
      }
    }
    if (d[i] != d[i - 1]) {
      if (o++) putchar(' ');
      printf("%d", count);
      count = 0;
    }
    if (flag) count++;
    flag = 1;
  }
  if (o++) putchar(' ');
  printf("%d", count);
  return 0;
}

int main() {
  int id, x, num;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &id, &num);
    for (int j = 0; j < num; j++) {
      scanf("%d", &x);
      g.edge[id][x] = 1;
    }
  }
  bfs();
  return 0;
}

```