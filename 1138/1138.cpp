#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void postorder(vector<int>& preorder, vector<int>& inorder, int root, int low,
               int high) {
  if (low == high) {
    printf("%d", preorder[root]);
    return;
  }
  int index = low;
  while (inorder[index] != preorder[root]) index++;
  int llen = index - low;
  if (llen) {
    postorder(preorder, inorder, root + 1, low, low + llen - 1);
  } else {
    postorder(preorder, inorder, root + llen + 1, low + llen + 1, high);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> preorder(n), inorder(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &preorder[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &inorder[i]);
  }
  postorder(preorder, inorder, 0, 0, n - 1);
  return 0;
}