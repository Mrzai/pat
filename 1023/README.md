# 1023 Have Fun with Numbers
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication.  Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation.  Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property.  That is, double a given number with $$k$$ digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

### Input Specification:

Each input contains one test case.  Each case contains one positive integer with no more than 20 digits.

### Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not.  Then in the next line, print the doubled number.

### Sample Input:
```in
1234567899
```

### Sample Output:
```out
Yes
2469135798
```
```cpp
#include <stdio.h>
#include <string.h>

int caculator(char* str, int& len);
int Reverse(char* str, int len);

int main() {
	char str[30] = { 0 };
	scanf("%s", str);														//输入
	int len = strlen(str);
	printf("%s", caculator(str, len) ? "Yes\n" : "No\n");	                        //输出
	printf(str);
}

int caculator(char* str, int &len) {
	int in = 0,
		count[10] = { 0 };
	Reverse(str, len);
	for (int i = 0; i < len; i++) {													//加法器
		int temp = str[i] - '0';
		count[temp]++;
		str[i] = temp * 2 % 10 + in + '0';
		if (temp * 2 >= 10) in = 1;
		else in = 0;
	}
	if (in) {
		str[len++] = in + '0';
		str[len] = '\0';
		Reverse(str, len);
		return 0;
	}
	Reverse(str, len);
	for (int i = 0; i < len; i++) {													//检验
		int temp = str[i] - '0';
		count[temp]--;
	}
	for (int i = 0; i < 10; i++) {
		if (count[i] != 0)
			return 0;
	}
	
	return 1;
}

int Reverse(char* str, int len) {												//字符串反转
	len--;
	for (int i = 0; i < len; i++, len--) {
		int temp = str[i];
		str[i] = str[len];
		str[len] = temp;
	}
	return 0;
}
```