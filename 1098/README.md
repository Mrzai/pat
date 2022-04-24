# 1098 Insertion or Heap Sort
According to Wikipedia:

**Insertion sort** iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

**Heap sort** divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to find the maximum.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

### Input Specification:

Each input file contains one test case.  For each case, the first line gives a positive integer $$N$$ ($$\le 100$$).  Then in the next line, $$N$$ integers are given as the initial sequence.  The last line contains the partially sorted sequence of the $$N$$ numbers.  It is assumed that the target sequence is always ascending.  All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial result.  Then run this method for one more iteration and output in the second line the resulting sequence.  It is guaranteed that the answer is unique for each test case.  All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

### Sample Input 1:
```in
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
```

### Sample Output 1:
```out
Insertion Sort
1 2 3 5 7 8 9 4 6 0
```

### Sample Input 2:
```
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
```

### Sample Output 2:
```
Heap Sort
5 4 3 1 0 2 6 7 8 9
```
```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void adjustheap(vector<int> &v, int k, int len) {
	int temp = v[k];
	for (int i = k * 2 + 1; i < len; i = i * 2 + 1) {
		if (i + 1 < len && v[i + 1] > v[i]) i++;
		if (temp >= v[i]) break;
		else {
			v[k] = v[i];
			k = i;
		}
	}
	v[k] = temp;
}

void buildheap(vector<int> &v, int len) {
	for (int i = len / 2 - 1; i >= 0; i--) {
		adjustheap(v, i, len);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int i, j, n;
	cin >> n;
	vector<int> v(n + 1), t(n + 1);
	for (i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (i = 0; i < n - 1 && t[i] <= t[i + 1]; i++);
	for (j = i + 1; j < n && v[j] == t[j]; j++);
	if (j == n) {
		cout << "Insertion Sort" << endl;
		sort(&v[0], &v[i + 2]);
	}
	else {
		cout << "Heap Sort" << endl;
		bool flag = true;
		buildheap(v, n);
		for (i = n; flag; i--) {
			if (v == t) flag = false;
			swap(v[0], v[i - 1]);
			adjustheap(v, 0, i - 1);
		}
	}
	for (i = 0; i < n; i++) {
		if (i) cout << ' ';
		cout << v[i];
	}
	return 0;
}
```