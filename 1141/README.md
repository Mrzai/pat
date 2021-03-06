# 1141 PAT Ranking of Institutions
After each PAT, the PAT Center will announce the ranking of institutions based on their students' performances. Now you are asked to generate the ranklist.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N ($$\le 10^5$$), which is the number of testees. Then N lines follow, each gives the information of a testee in the following format:

```
ID Score School
```

where `ID` is a string of 6 characters with the first one representing the test level: `B` stands for the basic level, `A` the advanced level and `T` the top level; `Score` is an integer in [0, 100]; and `School` is the institution code which is a string of no more than 6 English letters (case insensitive). Note: it is guaranteed that `ID` is unique for each testee.

### Output Specification:

For each case, first print in a line the total number of institutions. Then output the ranklist of institutions in nondecreasing order of their ranks in the following format:

```
Rank School TWS Ns
```

where `Rank` is the rank (start from 1) of the institution; `School` is the institution code (all in lower case); ; `TWS` is the **total weighted score** which is defined to be the integer part of `ScoreB/1.5 + ScoreA + ScoreT*1.5`, where `ScoreX` is the total score of the testees belong to this institution on level `X`; and `Ns` is the total number of testees who belong to this institution.

The institutions are ranked according to their `TWS`. If there is a tie, the institutions are supposed to have the same rank, and they shall be printed in ascending order of `Ns`. If there is still a tie, they shall be printed in alphabetical order of their codes.

### Sample Input:
```in
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
```

### Sample Output:
```out
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
```

```cpp
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct node {
  string id;
  int cnt;
  double score;
};

void tolower(string& s) {
  for (int i = 0; i < s.size(); i++) {
    s[i] = s[i] | 32;
  }
}

bool cmp(node a, node b) {
  if (a.score != b.score)
    return a.score > b.score;
  else if (a.cnt != b.cnt)
    return a.cnt < b.cnt;
  else
    return a.id < b.id;
}

int main() {
  ios::sync_with_stdio(false);
  int n, cnt = 1;
  double score;
  cin >> n;
  string id, school;
  vector<node> v(1);
  unordered_map<string, int> m;
  for (int i = 0; i < n; i++) {
    cin >> id >> score >> school;
    tolower(school);
    if (!m[school]) {
      v.push_back(node{school});
      m[school] = cnt++;
    }
    v[m[school]].cnt++;
    if (id[0] == 'A')
      v[m[school]].score += score;
    else if (id[0] == 'B')
      v[m[school]].score += score / 1.5;
    else
      v[m[school]].score += score * 1.5;
  }
  for (auto& it : v) {
    it.score = int(it.score);
  }
  sort(v.begin() + 1, v.end(), cmp);
  cout << v.size() - 1 << endl;
  for (int i = 1, temp; i < v.size(); i++) {
    if (i == 1 || v[i].score != v[i - 1].score) {
      cout << i << " " << v[i].id << " " << v[i].score << " " << v[i].cnt
           << endl;
      temp = i;
    } else {
      cout << temp << " " << v[i].id << " " << v[i].score << " " << v[i].cnt
           << endl;
    }
  }
  return 0;
}
```