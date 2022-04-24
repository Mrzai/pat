# 1089 Insert or Merge
According to Wikipedia:

**Insertion sort** iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

**Merge sort** works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted).  Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

### Input Specification:

Each input file contains one test case.  For each case, the first line gives a positive integer $$N$$ ($$\le 100$$).  Then in the next line, $$N$$ integers are given as the initial sequence.  The last line contains the partially sorted sequence of the $$N$$ numbers.  It is assumed that the target sequence is always ascending.  All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result.  Then run this method for one more iteration and output in the second line the resuling sequence.  It is guaranteed that the answer is unique for each test case.  All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

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
```in
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
```

### Sample Output 2:
```out
Merge Sort
1 2 3 8 4 5 7 9 0 6
```

**鸣谢用户 木子 补充数据！**
```cpp
#include <iostream>
#include <cstdio>
#include <vector> 
#include <algorithm>
using namespace std;

int num;

int main() {
	int i, j;
	vector<int> v, t;
	cin >> num;
	v.resize(num + 2);
	t.resize(num + 2);
	for (i = 1; i <= num; i++) {
		scanf("%d", &v[i]);
	}
	for (i = 1; i <= num; i++) {
		scanf("%d", &t[i]);
	}
	for (i = 1; i < num && t[i] <= t[i + 1]; i++);
	for (j = i + 1; j <= num && v[j] == t[j]; j++);
	if (j == num + 1) {
        cout << "Insertion Sort" << endl;
		sort(&v[1], &v[i + 2]);
	}
	else {
		bool flag = false;
		cout << "Merge Sort" << endl;
		for (i = 1; !flag; i *= 2) {
			if (t == v) flag = true;
			int k = 1;
			for (; k + 2 * i <= num; k += 2 * i)
				sort(&v[k], &v[k + 2 * i]);
			sort(&v[k], &v[num + 1]);
		}
	}
	for (int i = 1; i <= num; i++) {
		if (i - 1) putchar(' ');
		printf("%d", v[i]);
	}
	return 0;
}
```