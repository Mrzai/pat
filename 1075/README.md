# 1075 PAT Judge
The ranklist of PAT is generated from the status list, which shows the scores of the submissions.  This time you are supposed to generate the ranklist for PAT.

### Input Specification:

Each input file contains one test case.  For each case, the first line contains 3 positive integers, $$N$$ ($$\le 10^4$$), the total number of users, $$K$$ ($$\le 5$$), the total number of problems, and $$M$$ ($$\le 10^5$$), the total number of submissions.  It is then assumed that the user id's are 5-digit numbers from 00001 to $$N$$, and the problem id's are from 1 to $$K$$.  The next line contains $$K$$ positive integers `p[i]` (`i`=1, ..., $$K$$), where `p[i]` corresponds to the full mark of the i-th problem.  Then $$M$$ lines follow, each gives the information of a submission in the following format:
```
user_id problem_id partial_score_obtained
```
where `partial_score_obtained` is either $$-1$$ if the submission cannot even pass the compiler, or is an integer in the range [0, `p[problem_id]`].  All the numbers in a line are separated by a space.

### Output Specification:

For each test case, you are supposed to output the ranklist in the following format:
```
rank user_id total_score s[1] ... s[K]
```
where `rank` is calculated according to the `total_score`, and all the users with the same `total_score` obtain the same `rank`; and `s[i]` is the partial score obtained for the `i`-th problem.  If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position.  If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks.  For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems.  And if there is still a tie, then they must be printed in increasing order of their id's.  For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist.  It is guaranteed that at least one user can be shown on the ranklist.

### Sample Input:
```in
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
```

### Sample Output:
```out
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
```
```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct record {
	bool pass = false;
	int id;
	int grade[6] = { 0 };
	int sum = 0;
};

bool cmp(record a, record b) {
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.grade[0] != b.grade[0])
		return a.grade[0] > b.grade[0];
	else
		return a.id < b.id;
}

int main() {
	int n, k, m, id, index, score, p[6] = { 0 };
	cin >> n >> k >> m;
	vector<record> v(n + 1);
	for (int i = 1; i <= k; i++) {
		scanf("%d", p + i);
	}
	for (int i = 1; i <= n; i++) {
		fill(v[i].grade + 1, v[i].grade + 6, -1);
		v[i].id = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &id, &index, &score);
		v[id].grade[index] = max(score, v[id].grade[index]);
		if (score != -1) {
			v[id].pass = true;
		}
		else if (v[id].grade[index] == -1)
			v[id].grade[index] = -2;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (v[i].grade[j] == p[j])
				v[i].grade[0]++;
			if (v[i].grade[j] != -2 && v[i].grade[j] != -1)
				v[i].sum += v[i].grade[j];
		}
	}

	sort(v.begin() + 1, v.end(), cmp);
	for (int i = 1, temp = 0; i < v.size(); i++) {
		if (!v[i].pass) continue;
		if (v[i].sum == v[temp].sum) {
			printf("%d %05d %d", temp, v[i].id, v[i].sum);
		}
		else { 
			temp = i;
			printf("%d %05d %d", i, v[i].id, v[i].sum);
		}
		for (int j = 1; j <= k; j++) {
			if (v[i].grade[j] == -1)
				printf(" -");
			else if (v[i].grade[j] == -2)
				printf(" 0");
			else
				printf(" %d", v[i].grade[j]);
		}
		putchar('\n');
	}
	return 0;
}
```