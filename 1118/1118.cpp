#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define maxsize 10010
using namespace std;
vector<int> father(maxsize);

void initfather() {
  for (int i = 0; i < maxsize; i++) {
    father[i] = i;
  }
}

int find(int x) {
  int temp = x;
  while (x != father[x]) {
    x = father[x];
  }
  while (temp != father[temp]) {
    int n = temp;
    temp = father[temp];
    father[n] = x;
  }
  return x;
}

void Union(int x, int y) {
  int fa = find(x);
  int fb = find(y);
  if (fa != fb) father[fb] = fa;
}

int main() {
  initfather();
  int n, qt, treenum = 0, birdnum = 0;
  cin >> n;
  vector<bool> visited(maxsize);
  for (int i = 0, k; i < n; i++) {
    cin >> k;
    for (int j = 0, temp, fa; j < k; j++) {
      scanf("%d", &temp);
      if (j == 0) fa = temp;
      if (visited[temp]) Union(find(temp), find(fa));
      Union(fa, temp);
      visited[temp] = true;
    }
  }
  for (int i = 0; i < maxsize; i++) {
    if (visited[i]) {
      birdnum++;
      if (father[i] == i) treenum++;
    }
  }
  cout << treenum << ' ' << birdnum << endl;
  cin >> qt;
  for (int i = 0, qa, qb; i < qt; i++) {
    scanf("%d %d", &qa, &qb);
    if (find(qa) == find(qb)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}