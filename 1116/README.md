# 1116 Come on! Let's C
"Let's C" is a popular and fun programming contest hosted by the College of Computer Science and Technology, Zhejiang University. Since the idea of the contest is for fun, the award rules are funny as the following:

- 0、 The Champion will receive a "Mystery Award" (such as a BIG collection of students' research papers...).
- 1、 Those who ranked as a prime number will receive the best award -- the Minions (小黄人)!
- 2、 Everyone else will receive chocolates.

Given the final ranklist and a sequence of contestant ID's, you are supposed to tell the corresponding awards.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N ($$\le 10^4$$), the total number of contestants. Then N lines of the ranklist follow, each in order gives a contestant's ID (a 4-digit number). After the ranklist, there is a positive integer K followed by K query ID's.

### Output Specification:

For each query, print in a line `ID: award` where the award is `Mystery Award`, or `Minion`, or `Chocolate`. If the ID is not in the ranklist, print `Are you kidding?` instead. If the ID has been checked before, print `ID: Checked`.

### Sample Input:
```in
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
```

### Sample Output:
```out
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
```

```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
#define maxsize 10010
vector<bool> isprime(maxsize, true);

void initprime() {
	isprime[0] = isprime[1] = false;
	for (int i = 2; i < maxsize; i++) {
		if (isprime[i]) {
			for (int j = i * i; j < maxsize; j += i)
				isprime[j] = false;
		}
	}
}
int main() {
	int n;
	cin >> n;
	initprime();
	vector<int> v(maxsize, -1);
	string award[5] = { "Mystery Award", "Minion", "Chocolate", "Are you kidding?", "Checked"};
	for (int i = 1, id; i <= n; i++) {
		scanf("%d", &id);
		v[id] = i;
	}
	cin >> n;
	for (int i = 0, id, rank; i < n; i++) {
		scanf("%d", &id);
		rank = v[id];
		if (rank == 1)
			cout << setfill('0') << setw(4) << id << ": " << award[0] << endl;
		else if(rank != -1 && rank != -2 && isprime[rank])
			cout << setfill('0') << setw(4) << id << ": " << award[1] << endl;
		else if(rank != -1 && rank != -2)
			cout << setfill('0') << setw(4) << id << ": " << award[2] << endl;
		else if(rank == -1 )
			cout << setfill('0') << setw(4) << id << ": " << award[3] << endl;
		else if(rank == -2)
			cout << setfill('0') << setw(4) << id << ": " << award[4] << endl;
		v[id] = v[id] == -1 ? -1 : -2;
	}
	return 0;
}
```