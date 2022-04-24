#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct node {
  int lchild = -1, rchild = -1;
};

void isCBT(vector<node>& v, int root, int cnt) {
  queue<int> q;
  q.push(root);
  bool flag = false;
  while (true) {
    int temp = q.front();
    q.pop();
    if (temp == -1 && cnt) {
      cout << "NO" << ' ' << root;
      return;
    }
    cnt--;
    if (!cnt) {
      cout << "YES" << ' ' << temp;
      return;
    }
    q.push(v[temp].lchild);
    q.push(v[temp].rchild);
  }
}

int main() {
  int n, root = 0;
  cin >> n;
  vector<node> v(n);
  vector<bool> isroot(n, true);
  for (int i = 0; i < n; i++) {
    string l, r;  //非个位数不要忽略
    cin >> l >> r;
    if (l != "-") {
      v[i].lchild = stoi(l);
      isroot[stoi(l)] = false;
    }
    if (r != "-") {
      v[i].rchild = stoi(r);
      isroot[stoi(r)] = false;
    }
  }
  while (!isroot[root]) root++;
  isCBT(v, root, n);
  return 0;
}