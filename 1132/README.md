# 1132 Cut Integer
Cutting an integer means to cut a K digits lone integer Z into two integers of (K/2) digits long integers A and B. For example, after cutting Z = 167334, we have A = 167 and B = 334. It is interesting to see that Z can be devided by the product of A and B, as 167334 / (167 $$\times$$ 334) = 3. Given an integer Z, you are supposed to test if it is such an integer.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N ($$\le$$ 20). Then N lines follow, each gives an integer Z (10 $$\le$$ Z $$<2^{31}$$). It is guaranteed that the number of digits of Z is an even number.

### Output Specification:

For each case, print a single line `Yes` if it is such a number, or `No` if not.

### Sample Input:
```in
3
167334
2333
12345678
```

### Sample Output:
```out
Yes
No
No
```

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  int z;
  string input;
  cin >> z;
  while (z--) {
    cin >> input;
    string left = input.substr(0, input.size() / 2);
    string right = input.substr(input.size() / 2);
    if (stoi(right) && stoi(input) % (stoi(left) * stoi(right)) == 0) {
      cout << "Yes" << endl;
    } else
      cout << "No" << endl;
  }
  return 0;
}
```