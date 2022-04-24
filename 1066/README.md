# 1066 Root of AVL Tree
An AVL tree is a self-balancing binary search tree.  In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property.  Figures 1-4 illustrate the rotation rules.

<center>

![F1.jpg](~/8e3c8cca-d5ab-490b-be8b-c7101ffb94a4.jpg)
![F2.jpg](~/bcdb39fb-08b6-41d8-8a3d-96708e4ad97c.jpg)


![](~/33) 
![](~/34)
</center>
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

### Input Specification:

Each input file contains one test case.  For each case, the first line contains a positive integer $$N$$ ($$\le 20$$) which is the total number of keys to be inserted.  Then $$N$$ distinct integer keys are given in the next line.  All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print the root of the resulting AVL tree in one line.

### Sample Input 1:
```in
5
88 70 61 96 120
```

### Sample Output 1:
```out
70
```

### Sample Input 2:
```
7
88 70 61 96 120 90 65
```

### Sample Output 2:
```
88
```
```cpp
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

struct node {
  int id;
  node *left, *right;
};

void rotate2right(node*& root) {
  node* temp = root->left;
  root->left = temp->right;
  temp->right = root;
  root = temp;
}

void rotate2left(node*& root) {
  node* temp = root->right;
  root->right = temp->left;
  temp->left = root;
  root = temp;
}

void lr(node*& root) {
  rotate2left(root->left);
  rotate2right(root);
}

void rl(node*& root) {
  rotate2right(root->right);
  rotate2left(root);
}

int get_height(node* root) {
  if (root == NULL)
    return 0;
  else
    return max(get_height(root->left), get_height(root->right)) + 1;
}

void insert(int id, node*& root) {
  if (root == NULL) {
    root = new node;
    root->id = id;
    root->left = NULL;
    root->right = NULL;
  } else if (id < root->id) {
    insert(id, root->left);
    if (get_height(root->left) - get_height(root->right) == 2) {
      if (id < root->left->id) {
        rotate2right(root);
      } else {
        lr(root);
      }
    }
  } else {
    insert(id, root->right);
    if (get_height(root->left) - get_height(root->right) == -2) {
      if (id < root->right->id) {
        rl(root);
      } else {
        rotate2left(root);
      }
    }
  }
}

int main() {
  int num;
  cin >> num;
  node* root = NULL;
  for (int i = 0, temp; i < num; i++) {
    scanf("%d", &temp);
    insert(temp, root);
  }
  cout << root->id;
  return 0;
}
```