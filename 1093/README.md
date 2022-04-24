# 1093 Count PAT's
The string `APPAPT` contains two `PAT`'s as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.

Now given any string, you are supposed to tell the number of `PAT`'s contained in the string.

### Input Specification:

Each input file contains one test case. For each case, there is only one line giving a string of no more than $$10^5$$ characters containing only `P`, `A`, or `T`.

### Output Specification:

For each test case, print in one line the number of `PAT`'s contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.

### Sample Input:
```in
APPAPT
```

### Sample Output:
```out
2
```

```cpp
#include <iostream>
using namespace std;
#define max 1000000007
 
int main() {
    string s;
    int t = 0, a = 0;
    long long cnt = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'T') t++;
        else if (s[i] == 'A') a++;
    }
    int pb = 0, ta = t;
    for (int i = 0; a > 0; i++) {
        if (s[i] == 'A') {
            long long temp = pb * ta;
            cnt = (cnt + temp) % max;
            a--;
        }
        else if (s[i] == 'P') {
            pb++;
        }
        else
            ta--;
    }
    cout << cnt;
    return 0;
}
```