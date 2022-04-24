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
