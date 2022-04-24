#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
typedef struct node {
  int id;
  struct node *lchild, *rchild;
} node;

node* creatree(int* a, int l1, int h1, int* b, int l2, int h2) {
  node* bt = new node;
  bt->id = a[h1];
  int i = l2;
  for (; b[i] != a[h1]; i++)
    ;
  int llen = i - l2;
  int rlen = h2 - i;
  if (llen)
    bt->lchild = creatree(a, l1, l1 + llen - 1, b, l2, l2 + llen - 1);
  else
    bt->lchild = NULL;
  if (rlen)
    bt->rchild = creatree(a, h1 - rlen, h1 - 1, b, h2 - rlen + 1, h2);
  else
    bt->rchild = NULL;
  return bt;
}

int main() {
  int num, flag = 0;
  int input1[50], input2[50];

  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> input1[i];
  }
  for (int i = 0; i < num; i++) {
    cin >> input2[i];
  }
  node* t = creatree(input1, 0, num - 1, input2, 0, num - 1);
  queue<node*> q;
  q.push(t);

  while (!q.empty()) {
    node* temp = q.front();
    if (flag++) cout << ' ';
    cout << temp->id;
    q.pop();
    if (temp->lchild) {
      q.push(temp->lchild);
    }
    if (temp->rchild) {
      q.push(temp->rchild);
    }
  }
  return 0;
}
