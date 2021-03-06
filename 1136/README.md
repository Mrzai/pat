# 1136 A Delayed Palindrome
Consider a positive integer $$N$$ written in standard notation with $$k+1$$ digits $$a_i$$ as $$a_k \cdots a_1 a_0$$ with $$0 \le a_i < 10$$ for all $$i$$ and $$a_k > 0$$. Then $$N$$ is **palindromic** if and only if $$a_i = a_{k-i}$$ for all $$i$$. Zero is written 0 and is also palindromic by definition.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. Such number is called **a delayed palindrome**. (Quoted from https://en.wikipedia.org/wiki/Palindromic_number )

Given any positive integer, you are supposed to find its paired palindromic number.

### Input Specification:

Each input file contains one test case which gives a positive integer no more than 1000 digits.

### Output Specification:

For each test case, print line by line the process of finding the palindromic number. The format of each line is the following:
```
A + B = C
```
where `A` is the original number, `B` is the reversed `A`, and `C` is their sum. `A` starts being the input number, and this process ends until `C` becomes a palindromic number -- in this case we print in the last line `C is a palindromic number.`; or if a palindromic number cannot be found in 10 iterations, print `Not found in 10 iterations.` instead.

### Sample Input 1:
```in
97152
```

### Sample Output 1:
```out
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
```

### Sample Input 2:
```in
196
```

### Sample Output 2:
```out
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
```

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void add(string& a, string& b) {
  int in = 0;
  for (int i = 0, temp; i < a.size(); i++) {
    temp = a[i] - '0';
    a[i] = (a[i] - '0' + b[i] - '0' + in) % 10 + '0';
    in = temp + b[i] - '0' + in >= 10 ? 1 : 0;
  }
  if (in) a += '1';
  b = a;
  reverse(a.begin(), a.end());
}

int main() {
  ios::sync_with_stdio(false);
  int cnt = 0;
  string number, rnumber;
  cin >> number;
  rnumber = number;
  reverse(rnumber.begin(), rnumber.end());
  while (number != rnumber && cnt < 10) {
    cnt++;
    cout << number << " + " << rnumber;
    add(number, rnumber);
    cout << " = " << number << endl;
  }
  if (number == rnumber)
    cout << number << " is a palindromic number." << endl;
  else
    cout << "Not found in 10 iterations." << endl;
  return 0;
}
```