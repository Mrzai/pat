# 1138 Postorder Traversal
Suppose that all the keys in a binary tree are distinct positive integers. Given the preorder and inorder traversal sequences, you are supposed to output the first number of the postorder traversal sequence of the corresponding binary tree.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N ($$\le$$ 50,000), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print in one line the first number of the postorder traversal sequence of the corresponding binary tree.

### Sample Input:
```in
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
```

### Sample Output:
```out
3
```

```cpp
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
```