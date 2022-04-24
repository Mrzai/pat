# 1110 Complete Binary Tree
Given a tree, you are supposed to tell if it is a complete binary tree.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer $$N$$ ($$\le 20$$) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to $$N-1$$. Then $$N$$ lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a `-` will be put at the position. Any pair of children are separated by a space.

### Output Specification:

For each case, print in one line `YES` and the index of the last node if the tree is a complete binary tree, or `NO` and the index of the root if not. There must be exactly one space separating the word and the number.

### Sample Input 1:
```in
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
```

### Sample Output 1:
```out
YES 8
```

### Sample Input 2:
```in
8
- -
4 5
0 6
- -
2 3
- 7
- -
- -
```

### Sample Output 2:
```out
NO 1
```

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
		string l, r; //非个位数不要忽略
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
```