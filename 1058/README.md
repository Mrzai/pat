# 1058 A+B in Hogwarts
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute $$A+B$$ where $$A$$ and $$B$$ are given in the standard form of `Galleon.Sickle.Knut` (`Galleon` is an integer in [$$0, 10^7$$], `Sickle` is an integer in [0, 17), and `Knut` is an integer in [0, 29)).

### Input Specification:

Each input file contains one test case which occupies a line with $$A$$ and $$B$$ in the standard form, separated by one space.

### Output Specification:

For each test case you should output the sum of $$A$$ and $$B$$ in one line, with the same format as the input.

### Sample Input:
```in
3.2.1 10.16.27
```

### Sample Output:
```out
14.1.28
```

```cpp
#include <stdio.h>

int main() {

	int   sum_[2][3] = { 0 };
	char c;
	for (int i = 0, flag = 0, id = 0; (c = getchar()) != '\n';i++) {
		if (c == ' ') {
			flag = 1;
			id = 0;
			continue;
		}
		if (c == '.') id++;
		else
			sum_[flag][id] = (c - '0') + sum_[flag][id] * 10;
	}

	printf("%d.%d.%d", ((sum_[0][2] + sum_[1][2]) / 29 + sum_[0][1] + sum_[1][1]) / 17 + sum_[0][0] + sum_[1][0], ((sum_[0][2] + sum_[1][2]) / 29 + sum_[0][1] + sum_[1][1]) % 17,  (sum_[0][2] + sum_[1][2]) % 29);

	return 0;
}
```