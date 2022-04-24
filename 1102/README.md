# 1102 Invert a Binary Tree
The following is from Max Howell @twitter:
```
Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.
```
Now it's your turn to prove that YOU CAN invert a binary tree!

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer $$N$$ ($$\le 10$$) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to $$N-1$$. Then $$N$$ lines follow, each corresponds to a node from 0 to $$N-1$$, and gives the indices of the left and right children of the node. If the child does not exist, a `-` will be put at the position. Any pair of children are separated by a space.

### Output Specification:

For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

### Sample Input:
```in
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
```

### Sample Output:
```out
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
```

```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
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
	if (root < 0)
		return;
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
```