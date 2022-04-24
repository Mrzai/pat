# 1130 Infix Expression
Given a syntax tree (binary), you are supposed to output the corresponding infix expression, with parentheses reflecting the precedences of the operators.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N ($$\le$$ 20) which is the total number of nodes in the syntax tree. Then N lines follow, each gives the information of a node (the $$i$$-th line corresponds to the $$i$$-th node) in the format:
```
data left_child right_child
```
where `data` is a string of no more than 10 characters, `left_child` and `right_child` are the indices of this node's left and right children, respectively. The nodes are indexed from 1 to N. The NULL link is represented by $$-1$$. The figures 1 and 2 correspond to the samples 1 and 2, respectively.


| ![infix1.JPG](~/4d1c4a98-33cc-45ff-820f-c548845681ba.JPG) | ![infix2.JPG](~/b5a3c36e-91ad-494a-8853-b46e1e8b60cc.JPG) | 
| :--------: |:--------: | 
| Figure 1| Figure 2| 


### Output Specification:

For each case, print in a line the infix expression, with parentheses reflecting the precedences of the operators. Note that there must be no extra parentheses for the final expression, as is shown by the samples. There must be no space between any symbols.

### Sample Input 1:
```in
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1
```

### Sample Output 1:
```out
(a+b)*(c*(-d))
```

### Sample Input 2:
```in
8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1
```

### Sample Output 2:
```out
(a*2.35)+(-(str%871))
```

```cpp
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct node {
	string data;
	int lchild, rchild;
};

void inorder(vector<node>& v, int root) {
	static int ROOT = root;
	if (root > 0) {
		if ((v[root].lchild > 0 || v[root].rchild > 0) && root != ROOT)putchar('(');
		inorder(v, v[root].lchild);
		cout << v[root].data;
		inorder(v, v[root].rchild);
		if ((v[root].lchild > 0 || v[root].rchild > 0) && root != ROOT)putchar(')');
	}
}

int main() {
	int n, root = 1;
	cin >> n;
	vector<node> v(n + 1);
	vector<bool> isroot(n + 1, true);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].data >> v[i].lchild >> v[i].rchild;
		if (v[i].lchild > 0)	isroot[v[i].lchild] = false;
		if (v[i].rchild > 0)	isroot[v[i].rchild] = false;
	}
	while (!isroot[root]) root++;
	inorder(v, root);
	return 0;
}
```