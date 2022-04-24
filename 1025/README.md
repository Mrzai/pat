# 1025 PAT Ranking
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number $$N$$ ($$\le 100$$), the number of test locations. Then $$N$$ ranklists follow, each starts with a line containing a positive integer $$K$$ ($$\le 300$$), the number of testees, and then $$K$$ lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:
```
registration_number final_rank location_number local_rank
```
The locations are numbered from 1 to $$N$$. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

### Sample Input:
```in
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
```

### Sample Output:
```out
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
```

```cpp
#include <algorithm>
#include <iostream>
#define maxsize 30000
using namespace std;

struct test {
  string id;
  int local;
  int score;
  int rank;
};
bool cmp(test a, test b) {
  return a.score != b.score ? a.score > b.score : a.id < b.id;
}
int main() {
  test t[maxsize];
  int n, k, index = 0;
  cin >> n;

  for (int i = 0, j; i < n; i++) {
    cin >> k;
    for (j = 0; j < k; j++) {
      t[index].local = i + 1;
      cin >> t[index].id;
      cin >> t[index++].score;
    }
    sort(t + index - j, t + index, cmp);
    j = index - j;
    for (int k = 1, flag; j < index; j++, k++) {
      if (k == 1 || t[j - 1].score != t[j].score) {
        t[j].rank = k;
      } else
        t[j].rank = t[j - 1].rank;
    }
  }

  sort(t, t + index, cmp);
  cout << index << endl;
  for (int i = 0, flag; i < index; i++) {
    int final_rank;
    if (i == 0 || t[i - 1].score != t[i].score) {
      flag = i + 1;
      final_rank = i + 1;
    } else
      final_rank = flag;
    cout << t[i].id << " " << final_rank << " " << t[i].local << " "
         << t[i].rank << endl;
  }
  return 0;
}
```