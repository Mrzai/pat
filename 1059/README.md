# 1059 Prime Factors
Given any positive integer $$N$$, you are supposed to find all of its prime factors, and write them in the format $$N$$ = $${p_1}^{k_1}\times {p_2}^{k_2} \times \cdots \times {p_m}^{k_m}$$.

### Input Specification:

Each input file contains one test case which gives a positive integer $$N$$ in the range of **long int**.

### Output Specification:

Factor $$N$$ in the format $$N$$ `=` $$p_1$$`^`$$k_1$$`*`$$p_2$$`^`$$k_2$$`*`…`*`$$p_m$$`^`$$k_m$$, where $$p_i$$'s are prime factors of $$N$$ in increasing order, and the exponent $$k_i$$ is the number of $$p_i$$ -- hence when there is only one $$p_i$$, $$k_i$$ is 1 and must **NOT** be printed out.

### Sample Input:
```in
97532468
```

### Sample Output:
```out
97532468=2^2*11*17*101*1291
```

```cpp
#include <iostream>
#include <vector> 
using namespace std;


bool isPrime(int n) {
	if (n == 1 || n == 0)
		return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 2, ntemp = n; i <= ntemp; i++) {
		if(isPrime(i)) {
			while (ntemp % i == 0) {
				v.push_back(i);
				ntemp /= i;
			}
		}
	}
	cout << n << '=';
	if (n == 1) cout << 1;
	for (int i = 0, cnt = 1, flag = 0; i < v.size(); i++) {
		if (i + 1 < v.size() && v[i + 1] == v[i]) cnt++;
		else {
			if (flag++) cout << '*';
			if (cnt != 1) cout << v[i] << '^' << cnt;
			else cout << v[i];
			cnt = 1;
		}
	}
	return 0;
}
```