# 1010 Radix
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true?  The answer is `yes`, if 6 is a decimal number and 110 is a binary number.



Now for any pair of positive integers $$N_1$$ and $$N_2$$, your task is to find the radix of one number while that of the other is given.

### Input Specification:

Each input file contains one test case. Each case occupies a line which contains 4 positive integers:

```

N1 N2 tag radix

```

Here `N1` and `N2` each has no more than 10 digits.  A digit is less than its radix and is chosen from the set { 0-9, `a`-`z` } where 0-9 represent the decimal numbers 0-9, and `a`-`z` represent the decimal numbers 10-35.  The last number `radix` is the radix of `N1` if `tag` is 1, or of `N2` if `tag` is 2.

### Output Specification:

For each test case, print in one line the radix of the other number so that the equation `N1` = `N2` is true.  If the equation is impossible, print `Impossible`.  If the solution is not unique, output the smallest possible radix.

### Sample Input 1:
```in
6 110 1 10
```

### Sample Output 1:
```out
2
```

### Sample Input 2:
```in
1 ab 1 2
```

### Sample Output 2:
```out
Impossible
```

```cpp
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int tag, radix, n[2][10] = {0}, out = 0, max[2] = {0};
  string in1, in2;
  cin >> in1 >> in2 >> tag >> radix;

  for (int i = 0; i < in1.size(); i++) {
    if (in1[i] <= '9')
      n[0][i] = in1[i] - '0';
    else
      n[0][i] = in1[i] - 'a' + 10;
    max[0] = n[0][i] > max[0] ? n[0][i] : max[0];
  }

  for (int i = 0; i < in2.size(); i++) {
    if (in2[i] <= '9')
      n[1][i] = in2[i] - '0';
    else
      n[1][i] = in2[i] - 'a' + 10;
    max[1] = n[1][i] > max[1] ? n[1][i] : max[1];
  }

  long long sum = 0, temp;
  for (int i = 0; i < (tag == 1 ? in1.size() : in2.size()); i++) {
    sum = sum * radix + n[tag - 1][i];
  }

  long long low = max[!(tag - 1)] + 1, high = sum > low ? sum : low;
  while (low <= high) {
    temp = 0;
    long long mid = (low + high) / 2;
    for (int j = 0; j < (tag == 1 ? in2.size() : in1.size()); j++) {
      temp = temp * mid + n[!(tag - 1)][j];
    }
    if (temp == sum) {
      cout << mid;
      return 0;
    } else if (temp > sum || temp < 0)
      high = mid - 1;
    else
      low = mid + 1;
  }
  /*
  for (long long i = low; i <= high; i++) {
              temp = 0;
              for (int j = 0; j < (tag == 1 ? in2.size() : in1.size()); j++) {
                      temp = temp * i + n[!(tag - 1)][j];
              }
              if (temp > sum|| temp <0) break;
              if (temp == sum) {
                      cout << i << endl;
                      return 0;
              }
      }
  */
  cout << "Impossible" << endl;
  return 0;
}
```