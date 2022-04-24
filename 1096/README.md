# 1096 Consecutive Factors
Among all the factors of a positive integer N, there may exist several consecutive numbers.  For example, 630 can be factored as 3$$\times$$5$$\times$$6$$\times$$7, where 5, 6, and 7 are the three consecutive numbers.  Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.

### Input Specification:

Each input file contains one test case, which gives the integer N (1$$<$$N$$<2^{31}$$).

### Output Specification:

For each test case, print in the first line the maximum number of consecutive factors.  Then in the second line, print the smallest sequence of the consecutive factors in the format `factor[1]*factor[2]*...*factor[k]`, where the factors are listed in increasing order, and 1 is NOT included.

### Sample Input:
```in
630
```

### Sample Output:
```out
3
5*6*7
```
```cpp
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int num, k;
	vector<int> v;
	vector<int> temp;
	cin >> num;
	for (int i = 2;i <= sqrt(num);i++) {
		if (num % i == 0) {
			k = i;
			temp.push_back(i);
			for (int j = i + 1;num % (k * j) == 0;j++) {
				temp.push_back(j);
				k *= j;
			}
			if (temp.size() > v.size()) v.swap(temp);
			temp.resize(0);
		}
	}
	if (v.size() == 0) {
		cout << 1 << endl << num;
		return 0;
	}
	cout << v.size() << endl;
	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
		if (it == v.begin()) cout << *it;
		else cout << '*' << *it;
	}
	return 0;
}
```