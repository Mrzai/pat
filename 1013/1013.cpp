#include <cstdio>
#include <iostream>
#define maxsize 1000
using namespace std;

int dfs(int);
void dfs_(int, int *);

int edge[maxsize][maxsize] = {0};
int n, m, k;

int main() {
  cin >> n >> m >> k;
  while (m--) {
    int i, j;
    scanf("%d%d", &i, &j);
    edge[i][j] = edge[j][i] = 1;
  }
  for (int i = 0; i < k; i++) {
    int check;
    scanf("%d", &check);
    int roads = dfs(check);
    printf("%d\n", roads - 1);
  }

  return 0;
}

int dfs(int check) {
  int visited[maxsize] = {0};
  visited[check] = 1;
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      count++;
      dfs_(i, visited);
    }
  }
  return count;
}

void dfs_(int i, int *visited) {
  visited[i] = 1;
  for (int j = 1; j <= n; j++) {
    if (edge[i][j] && !visited[j]) {
      dfs_(j, visited);
    }
  }
}