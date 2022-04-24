# 1105 Spiral Matrix
This time your job is to fill a sequence of $$N$$ positive integers into a **spiral matrix** in non-increasing order. A spiral matrix is filled in from the first element at the upper-left corner, then move in a clockwise spiral. The matrix has $$m$$ rows and $$n$$ columns, where $$m$$ and $$n$$ satisfy the following: $$m\times n$$ must be equal to $$N$$; $$m\ge n$$; and $$m-n$$ is the minimum of all the possible values.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer $$N$$. Then the next line contains $$N$$ positive integers to be filled into the spiral matrix. All the numbers are no more than $$10^4$$. The numbers in a line are separated by spaces.

### Output Specification:

For each test case, output the resulting matrix in $$m$$ lines, each contains $$n$$ numbers. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

### Sample Input:
```in
12
37 76 20 98 76 42 53 95 60 81 58 93
```

### Sample Output:
```out
98 95 93
42 37 81
53 20 76
58 60 76
```

```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	int num, m, n, k = 0;
	cin >> num;
	vector<int> v(num);
	
	for (int i = 0; i < num; i++) {
		scanf("%d", &v[i]);
	}
	for (int i = 1, j = num; i <= j; i++, j = num/i) {
		if (i * j == num) {
			m = j;
			n = i;
		}
	}
	vector<vector<int>> temp(m, vector<int>(n));
	bool isplus = true;
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0, j = -1, x = n, y = m, z = 0, w = 1; k < num;) {
		if (isplus) {
			j++;
			while (j < x) {
				temp[i][j] = v[k++];
				j++;
			}
			j--;
			x--;
			i++;
			while (i < y) {
				temp[i][j] = v[k++];
				i++;
			}
			i--;
			y--;
		}
		else {
			j--;
			while (j >= z) {
				temp[i][j] = v[k++];
				j--;
			}
			j++;
			z++;
			i--;
			while (i >= w) {
				temp[i][j] = v[k++];
				i--;
			}
			i++;
			w++;
		}
		isplus = !isplus;
	}
	for (int i = 0, j = 0; i < m; i++, j = 0) {
		while (j < n) {
			if (j) putchar(' ');
			printf("%d", temp[i][j]);
			j++;
		}
		putchar('\n');
	}
	return 0;
}
```