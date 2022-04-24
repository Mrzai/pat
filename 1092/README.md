# 1092 To Buy or Not to Buy
Eva would like to make a string of beads with her favorite colors so she went to a small shop to buy some beads. There were many colorful strings of beads. However the owner of the shop would only sell the strings in whole pieces. Hence Eva must check whether a string in the shop contains all the beads she needs. She now comes to you for help: if the answer is `Yes`, please tell her the number of extra beads she has to buy; or if the answer is `No`, please tell her the number of beads missing from the string.

For the sake of simplicity, let's use the characters in the ranges [0-9], [a-z], and [A-Z] to represent the colors. For example, the 3rd string in Figure 1 is the one that Eva would like to make. Then the 1st string is okay since it contains all the necessary beads with 8 extra ones; yet the 2nd one is not since there is no black bead and one less red bead.


![figbuy.jpg](~/b7e2ffa6-8819-436d-ad79-a41263abe914.jpg)


Figure 1

### Input Specification:

Each input file contains one test case. Each case gives in two lines the strings of no more than 1000 beads which belong to the shop owner and Eva, respectively.

### Output Specification:

For each test case, print your answer in one line. If the answer is `Yes`, then also output the number of extra beads Eva has to buy; or if the answer is `No`, then also output the number of beads missing from the string. There must be exactly 1 space between the answer and the number.

### Sample Input 1:
```in
ppRYYGrrYBR2258
YrR8RrY
```

### Sample Output 1:
```out
Yes 8
```

### Sample Input 2:
```in
ppRYYGrrYB225
YrR8RrY
```

### Sample Output 2:
```out
No 2
```

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
	int temp[62] = { 0 }, a = 0, b = 0;
	string str;
	cin >> str;

	for (int i = 0;i < str.length();i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			temp[str[i] - '0']++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			temp[str[i] - 'A' + 10]++;
		}
		else
			temp[str[i] - 'a' + 36]++;
	}
    
	cin >> str;
	for (int i = 0;i < str.length();i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			temp[str[i] - '0']--;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			temp[str[i] - 'A' + 10]--;
		}
		else
			temp[str[i] - 'a' + 36]--;
	}

	for (int i = 0;i < 62;i++) {
		if (temp[i] > 0)
			a += temp[i];
		if (temp[i] < 0)
			b -= temp[i];
	}
	if (b) {
		cout << "No " << b << endl;
	}
	else
		cout << "Yes " << a << endl;
	return 0;
}
```