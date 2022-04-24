#include <stdio.h>
#define inf 99999
typedef struct {
  int edge[500][500];
} graph;

graph g;
int N, M, C1, C2, weight[500] = {0}, res[500] = {0}, num[500] = {0};

int dijsktra() {  //处理数据
  int dist[500], visited[500] = {0};

  for (int i = 0; i < N; i++) {
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
    for (int j = 0; j < N; j++) {
      if (!visited[j] && g.edge[u][j] != inf) {
        if (g.edge[u][j] + dist[u] < dist[j]) {
          dist[j] = g.edge[u][j] + dist[u];
          num[j] = num[u];
          weight[j] = weight[u] + res[j];
        } else if (g.edge[u][j] + dist[u] == dist[j]) {
          num[j] += num[u];
          if (weight[u] + res[j] > weight[j]) weight[j] = weight[u] + res[j];
        }
      }
    }
  }
  return 0;
}

int main() {  //处理输入输出
  scanf("%d%d%d%d", &N, &M, &C1, &C2);

  for (int i = 0; i < N; i++) {
    scanf("%d", res + i);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j)
        g.edge[i][j] = 0;
      else
        g.edge[i][j] = inf;
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
