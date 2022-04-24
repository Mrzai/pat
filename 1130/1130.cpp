#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct node {
  string data;
  int lchild, rchild;
};

void inorder(vector<node>& v, int root) {
  static int ROOT = root;
  if (root > 0) {
    if ((v[root].lchild > 0 || v[root].rchild > 0) && root != ROOT)
      putchar('(');
    inorder(v, v[root].lchild);
    cout << v[root].data;
    inorder(v, v[root].rchild);
    if ((v[root].lchild > 0 || v[root].rchild > 0) && root != ROOT)
      putchar(')');
  }
}

int main() {
  int n, root = 1;
  cin >> n;
  vector<node> v(n + 1);
  vector<bool> isroot(n + 1, true);
  for (int i = 1; i <= n; i++) {
    cin >> v[i].data >> v[i].lchild >> v[i].rchild;
    if (v[i].lchild > 0) isroot[v[i].lchild] = false;
    if (v[i].rchild > 0) isroot[v[i].rchild] = false;
  }
  while (!isroot[root]) root++;
  inorder(v, root);
  return 0;
}