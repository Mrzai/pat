# 1016 Phone Bills
A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

### Input Specification:

Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number $$N$$ ($$\le 1000$$), followed by $$N$$ lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (`MM:dd:HH:mm`), and the word `on-line` or `off-line`.

For each test case, all dates will be within a single month. Each `on-line` record is paired with the chronologically next record for the same customer provided it is an `off-line` record. Any `on-line` records that are not paired with an `off-line` record are ignored, as are `off-line` records not paired with an `on-line` record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

### Output Specification:

For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (`dd:HH:mm`), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

### Sample Input:
```in
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
```

### Sample Output:
```out
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
```

```cpp
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct record {
  int state;
  string name;
  int time[4];
  int time_;
};

int rate[25], num;

bool cmp(record a, record b) {
  return a.name == b.name ? a.time_ < b.time_ : a.name < b.name;
}

double cost(record n) {
  double total = n.time[1] * rate[24] * 60 + n.time[3] * rate[n.time[2]];
  for (int j = 0; j < n.time[2]; j++) {
    total += rate[j] * 60;
  }
  return total / 100;
}

int main() {
  for (int i = 0; i < 24; i++) {
    scanf("%d", rate + i);
    rate[24] += rate[i];
  }
  scanf("%d", &num);
  vector<record> r(num);
  for (int i = 0; i < num; i++) {
    string temp;
    cin >> r[i].name;
    scanf("%d:%d:%d:%d", r[i].time, r[i].time + 1, r[i].time + 2,
          r[i].time + 3);
    cin >> temp;
    r[i].state = (temp == "on-line") ? 1 : 0;
    r[i].time_ = (r[i].time[1] * 24 + r[i].time[2]) * 60 + r[i].time[3];
  }

  sort(r.begin(), r.end(), cmp);
  map<string, vector<record>> cus;

  for (int i = 1; i < num; i++) {
    if (r[i].name == r[i - 1].name && r[i].state == 0 && r[i - 1].state == 1) {
      cus[r[i].name].push_back(r[i - 1]);
      cus[r[i].name].push_back(r[i]);
    }
  }
  for (auto it = cus.begin(); it != cus.end(); it++) {
    vector<record> temp = it->second;
    cout << it->first;
    printf(" %02d\n", temp[0].time[0]);
    double total = 0;
    for (int i = 1; i < temp.size(); i += 2) {
      double t = cost(temp[i]) - cost(temp[i - 1]);
      printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].time[1],
             temp[i - 1].time[2], temp[i - 1].time[3], temp[i].time[1],
             temp[i].time[2], temp[i].time[3],
             temp[i].time_ - temp[i - 1].time_, t);
      total += t;
    }
    printf("Total amount: $%.2f\n", total);
  }

  return 0;
}

```