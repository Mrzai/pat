# 1020 Tree Traversals
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer $$N$$ ($$\le 30$$), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

### Sample Input:
```in
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
```

### Sample Output:
```out
4 1 6 3 5 7 2
```

```cpp
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;
typedef struct node{
	int id;
	struct node* lchild, * rchild;
}node;

node* creatree(int* a, int l1, int h1, int* b, int l2, int h2) {
	node* bt = new node;
	bt->id = a[h1];
	int i = l2;
	for (; b[i] != a[h1]; i++);
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


```