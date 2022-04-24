# 1007 Maximum Subsequence Sum
Given a sequence of $$K$$ integers { $$N_1$$, $$N_2$$, ..., $$N_K$$ }. A continuous subsequence is defined to be { $$N_i$$, $$N_{i+1}$$, ..., $$N_j$$ } where $$1 \le i \le j \le K$$. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence. 

### Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer $$K$$ ($$\le 10000$$). The second line contains $$K$$ numbers, separated by a space. 

### Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices $$i$$ and $$j$$ (as shown by the sample case). If all the $$K$$ numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence. 

### Sample Input:
```in
10
-10 1 2 3 4 -5 -23 3 7 -21
```

### Sample Output:
```out
10 1 4
```
```cpp
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void dp(vector<int>& v);

int main() {
  int num;
  vector<int> v;
  cin >> num;
  while (num--) {
    int temp;
    cin >> temp;
    v.push_back(temp);
  }
  dp(v);
  return 0;
}

void dp(vector<int>& v) {
  int cur_num = v[0], max_num = v[0], low = v[0], low_ = v[0], high = v[0],
      high_ = v[0], flag = 1;

  for (int i = 0; i < v.size(); i++) {
    if (v[i] >= 0) {
      flag = 0;
      break;
    }
  }
  for (int i = 1; i < v.size(); i++) {
    if (v[i] > v[i] + cur_num) {
      cur_num = v[i];
      low = v[i];
      high = v[i];
    } else {
      cur_num = cur_num + v[i];
      high = v[i];
    }
    if (cur_num > max_num) {
      max_num = cur_num;
      low_ = low;
      high_ = high;
    }
  }
  if (flag) {
    cout << '0' << ' ' << v[0] << ' ' << v[v.size() - 1] << endl;
    return;
  }
  cout << max_num << ' ' << low_ << ' ' << high_ << endl;
}
```