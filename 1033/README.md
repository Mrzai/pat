# 1033 To Fill or Not to Fill
With highways available, driving a car from Hangzhou to any other city is easy.  But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time.  Different gas station may give different price.  You are asked to carefully design the cheapest route to go.

### Input Specification:

Each input file contains one test case.  For each case, the first line contains 4 positive numbers: $$C_{max}$$ ($$\le$$ 100), the maximum capacity of the tank; $$D$$ ($$\le$$30000), the distance between Hangzhou and the destination city; $$D_{avg}$$ ($$\le$$20), the average distance per unit gas that the car can run; and $$N$$ ($$\le$$ 500), the total number of gas stations.  Then $$N$$ lines follow, each contains a pair of non-negative numbers: $$P_i$$, the unit gas price, and $$D_i$$ ($$\le D$$), the distance between this station and Hangzhou, for $$i=1,\cdots ,N$$.  All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print the cheapest price in a line, accurate up to 2 decimal places.  It is assumed that the tank is empty at the beginning.  If it is impossible to reach the destination, print `The maximum travel distance = X` where `X` is the maximum possible distance the car can run, accurate up to 2 decimal places.

### Sample Input 1:
```in
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
```

### Sample Output 1:
```out
749.17
```

### Sample Input 2:
```
50 1300 12 2
7.10 0
7.00 600
```

### Sample Output 2:
```
The maximum travel distance = 1200.00
```
```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct station {
  float price;
  float dis;
};

bool cmp(station a, station b) { return a.dis < b.dis; }
int main() {
  float c, d1, d2, cost = 0, c_temp = 0;
  int n;
  cin >> c >> d1 >> d2 >> n;
  vector<station> s(n + 1);
  for (int i = 0; i < n; i++) {
    scanf("%f %f", &s[i].price, &s[i].dis);
  }
  s[n].dis = d1;
  s[n].price = 0;
  sort(s.begin(), s.end(), cmp);
  if (s[0].dis != 0) {
    printf("The maximum travel distance = 0.00");
    return 0;
  }
  for (int i = 0; i < n;) {
    if (s[i + 1].dis - s[i].dis > c * d2) {
      printf("The maximum travel distance = %.2f", s[i].dis + c * d2);
      return 0;
    }
    int min = 1, flag = 0;
    float min_price = s[i + 1].price;
    for (int j = 1; s[i + j].dis - s[i].dis <= c * d2 && (i + j) <= n; j++) {
      if (s[i + j].price <= s[i].price) {
        flag = j;
        break;
      }

      if (s[i + j].price < min_price) {
        min = j;
        min_price = s[i + j].price;
      }
    }
    if (flag) {
      float dis_temp = s[i + flag].dis - s[i].dis;
      cost += s[i].price * (dis_temp / d2 - c_temp);
      c_temp = 0;
      i += flag;
    } else {
      float dis_temp = s[i + min].dis - s[i].dis;
      cost += s[i].price * (c - c_temp);
      c_temp = c - dis_temp / d2;
      i += min;
    }
  }
  printf("%.2f", cost);
  return 0;
}

```