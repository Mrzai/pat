#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#define maxsize 1000000
using namespace std;
bool visited[maxsize] = {false};
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