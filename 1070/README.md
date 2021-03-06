# 1070 Mooncake
Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. Many types of fillings and crusts can be found in traditional mooncakes according to the region's culture. Now given the inventory amounts and the prices of all kinds of the mooncakes, together with the maximum total demand of the market, you are supposed to tell the maximum profit that can be made.

Note: partial inventory storage can be taken. The sample shows the following situation: given three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, the best we can do is to sell 150 thousand tons of the second kind of mooncake, and 50 thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers $$N$$ ($$\le 1000$$), the number of different kinds of mooncakes, and $$D$$ ($$\le 500$$ thousand tons), the maximum total demand of the market. Then the second line gives the positive inventory amounts (in thousand tons), and the third line gives the positive prices (in billion yuans) of $$N$$ kinds of mooncakes. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 decimal places.

### Sample Input:
```in
3 200
180 150 100
7.5 7.2 4.5
```

### Sample Output:
```out
9.45
```

```cpp
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
struct cake {
  float a, b;
} c[1000];
bool cmp(cake x, cake y) { return x.b / x.a > y.b / y.a; }
int main() {
  int num;
  float demand, cnt = 0.0, profit = 0.0;
  cin >> num >> demand;
  for (int i = 0; i < num; i++) {
    scanf("%f", &c[i].a);
  }
  for (int i = 0; i < num; i++) {
    scanf("%f", &c[i].b);
  }
  sort(c, c + num, cmp);
  for (int i = 0; i < num && cnt < demand; i++) {
    if (demand - cnt >= c[i].a) {
      cnt += c[i].a;
      profit += c[i].b;
    } else {
      profit += ((demand - cnt) / c[i].a * c[i].b);
      cnt = demand;
    }
  }
  printf("%.2f", profit);
  return 0;
}
```