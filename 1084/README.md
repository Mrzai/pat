# 1084 Broken Keyboard
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

### Input Specification:

Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or `_` (representing the space). It is guaranteed that both strings are non-empty.

### Output Specification:

For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

### Sample Input:
```in
7_This_is_a_test
_hs_s_a_es
```

### Sample Output:
```out
7TI
```

```cpp
#include <stdio.h>
#include <string.h>
#define maxsize 100

int main() {
	char str1[maxsize] = { 0 }, str2[maxsize] = { 0 };
	int worn[maxsize] = { 0 }, index = 0;
	
	scanf("%s%s", str1, str2);
	for (int i = 0, j = 0;i < strlen(str1);i++) {
		if (str1[i] == str2[j]) j++;
		else {
			if (str1[i] >= '0' && str1[i] <= '9') index = str1[i] - '0';
			else if (str1[i] >= 'a' && str1[i] <= 'z') index = str1[i] - 'a' + 10;
			else if (str1[i] >= 'A' && str1[i] <= 'Z')index = str1[i] - 'A' + 10;
			else index = 36;
			if (!worn[index]) {
				worn[index] = 1;
				if (index < 10) putchar(index + '0');
				else if (index < 36) putchar(index - 10 + 'A');
				else if (index == 36) putchar('_');
				else continue;
			}
		}
	}
	
	return 0;
}
```