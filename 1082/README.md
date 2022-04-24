# 1082 Read Number in Chinese
Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output `Fu` first if it is negative. For example, -123456789 is read as `Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu`. Note: zero (`ling`) must be handled correctly according to the Chinese tradition. For example, 100800 is `yi Shi Wan ling ba Bai`.

### Input Specification:

Each input file contains one test case, which gives an integer with no more than 9 digits.

### Output Specification:

For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.

### Sample Input 1:
```in
-123456789
```

### Sample Output 1:
```out
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
```

### Sample Input 2:
```in
100800
```

### Sample Output 2:
```out
yi Shi Wan ling ba Bai
```

```cpp
#include <string>
#include <iostream>
using namespace std;

int main() {
	char num[][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	char decimal[][5] = { "Fu", "Qian", "Wan", "Shi", "Bai", "Yi" };
	string s;
	cin >> s;
	int i = 0;
	if (s[0] == '-') printf(decimal[i++]);
    if(s[0] == '0'){
        printf(num[0]);
        return 0;
    }
	for (; i < s.size(); i++) {
		int j = s.size() - i;
		
		if (s[i] != '0') {
			if (i) putchar(' ');
			printf("%s", num[s[i] - '0']);
		}
		else if (i + 1 < s.size() && s[i + 1] != '0') {
			if (i) putchar(' ');
			printf("%s", num[0]);
			continue;
		}
		else if(j % 4 != 1)
			continue;
		if (j % 4 != 1)
			printf(" %s", decimal[j % 4 + 1]);
		else if (j == 5)
			printf(" %s", decimal[2]);
		else if (j == 9)
			printf(" %s", decimal[5]);
	}
	return 0;
}
```