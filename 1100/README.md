# 1100 Mars Numbers
People on Mars count their numbers with base 13:

- Zero on Earth is called "tret" on Mars.
- The numbers 1 to 12 on Earth is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
- For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.

For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.

### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer $$N$$ ($$< 100$$). Then $$N$$ lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.

### Output Specification:

For each number, print in a line the corresponding number in the other language.

### Sample Input:
```in
4
29
5
elo nov
tam
```

### Sample Output:
```out
hel mar
may
115
13
```

```cpp
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main() {
	string s[25] = { "tret",  "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" ,"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	map<string, int> m;
	for (int i = 0; i < 13;i++) {
		m[s[i]] = i;
	}
	for (int i = 13;i < 25;i++) {
		m[s[i]] = (i - 12) * 13;
	}

	int num;
	cin >> num;
	getchar();
	while (num--) {
		string in;
		getline(cin, in);
		if (in.length() > 4) {
			string str1 = in.substr(0, 3);
			string str2 = in.substr(4);
			cout << m[str1] + m[str2] << endl;
		}
		else if (in[0] <= '9' && in[0] >= '0') {
			int num = 0;
			for (auto it = in.begin();it != in.end();it++) {
				num = num * 10 + *it - '0';
			}
			if ((num / 13) && (num % 13)) 
				cout << s[num / 13 + 12] << ' ' << s[num % 13] << endl;
			else if (num / 13)
				cout << s[num / 13 + 12] << endl;
			else
				cout << s[num % 13] << endl;
		}
		else
			cout << m[in] << endl;
	}
	return 0;
}
```