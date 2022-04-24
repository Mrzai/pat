# 1081 Rational Sum
Given $$N$$ rational numbers in the form `numerator/denominator`, you are supposed to calculate their sum.

### Input Specification:

Each input file contains one test case. Each case starts with a positive integer $$N$$ ($$\le 100$$), followed in the next line $$N$$ rational numbers `a1/b1 a2/b2 ...` where all the numerators and denominators are in the range of **long int**. If there is a negative number, then the sign must appear in front of the numerator.

### Output Specification:

For each test case, output the sum in the simplest form `integer numerator/denominator` where `integer` is the integer part of the sum, `numerator` $$<$$ `denominator`, and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.

### Sample Input 1:
```in
5
2/5 4/15 1/30 -2/60 8/3
```

### Sample Output 1:
```out
3 1/3
```

### Sample Input 2:
```in
2
4/3 2/3
```

### Sample Output 2:
```out
2
```

### Sample Input 3:
```in
3
1/3 -1/6 1/8
```

### Sample Output 3:
```out
7/24
```

```cpp
#include <stdio.h>

int main() {
	long long int in[2] = { 0 }, out[2] = { 0, 1 };
	int num;
	scanf("%d", &num);
	while (num--) {
		scanf("%lld/%lld", in, in + 1);
		out[0] = in[0] * out[1] + in[1] * out[0];
		out[1] = in[1] * out[1];
		int M = out[1] < out[1] ? out[1] : out[1];
		for (int i = 2;i <= M;i++) {
			if (out[0]%i==0 && out[1] %i==0) {
				out[0] /= i;
				out[1] /= i;
                M /= i;
				i--;
			}
		}
	}
	if (out[1] == 1)
		printf("%lld\n", out[0]);
	else if (out[0] > out[1]) {
		long long int temp = out[0] / out[1];
		out[0] %= out[1];
		printf("%lld %lld/%lld\n", temp, out[0] ,out[1] );
	}
	else
		printf("%lld/%lld\n", out[0], out[1]);
	return 0;
}
```