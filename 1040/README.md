# 1040 Longest Symmetric String
Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given `Is PAT&TAP symmetric?`, the longest symmetric sub-string is `s PAT&TAP s`, hence you must output `11`.

### Input Specification:

Each input file contains one test case which gives a non-empty string of length no more than 1000.

### Output Specification:

For each test case, simply print the maximum length in a line.

### Sample Input:
```in
Is PAT&TAP symmetric?
```

### Sample Output:
```out
11
```

```cpp
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int max_len = 0;
  string s;
  getline(cin, s);
  int end = s.size();
  for (int i = 0; i < end; i++) {
    int len = end - i;
    for (int j = end - 1, k = i, temp = end - 1; j > k;) {
      if (s[j] == s[k]) {
        k++;
        j--;
      } else {
        j = temp - 1;
        temp--;
        k = i;
        len = j - k + 1;
      }
    }
    max_len = len > max_len ? len : max_len;
  }
  cout << max_len;
}
```