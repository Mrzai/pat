#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct node {
  int level;
  int lchild = -1, rchild = -1;
};

int root, n;
vector<node> v;
vector<int> index;

void invert(int root, int level) {
  if (root < 0) return;
  invert(v[root].lchild, level + 1);
  invert(v[root].rchild, level + 1);
  swap(v[root].lchild, v[root].rchild);
  v[root].level = level;
}

void inorder(int root) {
  static int i = 0;
  if (root >= 0) {
    inorder(v[root].lchild);
    index[i++] = root;
    inorder(v[root].rchild);
  }
}
bool cmp(int i, int j) { return v[i].level < v[j].level; }
int main() {
  cin >> n;
  v.resize(n);
  index.resize(n);
  vector<bool> isroot(n, true);
  for (int i = 0; i < n; i++) {
    char temp;
    cin >> temp;
    if (temp != '-') {
      v[i].lchild = temp - '0';
      isroot[temp - '0'] = false;
    }
    cin >> temp;
    if (temp != '-') {
      v[i].rchild = temp - '0';
      isroot[temp - '0'] = false;
    }
  }
  for (int i = 0; i < n; i++) {
    if (isroot[i]) {
      root = i;
      break;
    }
  }
  invert(root, 1);
  inorder(root);
  vector<int> levelorder = index;
  sort(levelorder.begin(), levelorder.end(), cmp);
  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", levelorder[i]);
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", index[i]);
  }
}