# 1108 Finding Average
The basic task is simple: given $$N$$ real numbers, you are supposed to calculate their average. But what makes it complicated is that some of the input numbers might not be legal. A **legal** input is a real number in [$$-1000, 1000$$] and is accurate up to no more than 2 decimal places. When you calculate the average, those illegal numbers must not be counted in.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer $$N$$ ($$\le 100$$). Then $$N$$ numbers are given in the next line, separated by one space.

### Output Specification:

For each illegal input number, print in a line `ERROR: X is not a legal number` where `X` is the input. Then finally print in a line the result: `The average of K numbers is Y` where `K` is the number of legal inputs and `Y` is their average, accurate to 2 decimal places. In case the average cannot be calculated, output `Undefined` instead of `Y`. In case `K` is only 1, output `The average of 1 number is Y` instead.

### Sample Input 1:
```in
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
```

### Sample Output 1:
```out
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
```

### Sample Input 2:
```in
2
aaa -9999
```

### Sample Output 2:
```out
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
```

```cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int num, k = 0;
  double count = 0, temp;
  cin >> num;

  while (num--) {
    int flag = 0;
    char s[50], t[50];
    cin >> s;
    sscanf(s, "%lf", &temp);
    sprintf(t, "%.2f", temp);

    for (int i = 0; i < strlen(s); i++) {
      if (s[i] != t[i]) {
        flag = 1;
        break;
      }
    }

    if (flag || temp < -1000 || temp > 1000) {
      cout << "ERROR: " << s << " is not a legal number" << endl;
      continue;
    }
    count += temp;
    k++;
  }

  if (k > 1)
    printf("The average of %d numbers is %.2lf", k, count / k);
  else if (k == 1)
    printf("The average of 1 number is %.2lf", count);
  else
    printf("The average of 0 numbers is Undefined");
  return 0;
}

```