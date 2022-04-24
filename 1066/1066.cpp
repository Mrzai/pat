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