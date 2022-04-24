# 1002 A+B for Polynomials
This time, you are supposed to find $$A+B$$ where $$A$$ and $$B$$ are two polynomials.

### Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: 

$$K$$ $$N_1$$ $$a_{N_1}$$ $$N_2$$ $$a_{N_2}$$ ... $$N_K$$ $$a_{N_K}$$

where $$K$$ is the number of nonzero terms in the polynomial, $$N_i$$ and $$a_{N_i}$$ ($$i=1, 2, \cdots , K$$) are the exponents and coefficients, respectively. It is given that $$1 \le K \le 10$$，$$0 \le N_K < \cdots < N_2 < N_1 \le 1000$$.

### Output Specification:

For each test case you should output the sum of $$A$$ and $$B$$ in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

### Sample Input:
```in
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```

### Sample Output:
```out
3 2 1.5 1 2.9 0 3.2
```
```cpp
#include <cstdio>
#include <iostream>
#define maxsize 1001
using namespace std;

int main() {
	int k, flag = 0, count = 0;
	float po[maxsize] = { 0 };
	scanf("%d", &k);
	while (k--) {
		int ex;
		float re;
		scanf("%d %f", &ex, &re);
		//if (po[ex] == 0.0) count++;
		po[ex] += re;
	}
	scanf("%d", &k);
	while (k--) {
		int ex;
		float re;
		scanf("%d %f", &ex, &re);
		//if (po[ex] == 0.0) count++;
		po[ex] += re;
	}
    for (int i = 1000; i >= 0; i--) {
		if (po[i] != 0) {
			count++;
		}
	}
	cout << count;
	for (int i = 1000; i >= 0; i--) {
		if (po[i]!=0.0) {
			printf(" %d %.1f", i, po[i]);
		}
	}
    return 0;
}
```