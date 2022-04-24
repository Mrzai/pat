# 1137 Final Grading
For a student taking the online course "Data Structures" on China University MOOC (http://www.icourse163.org/), to be qualified for a certificate, he/she must first obtain no less than 200 points from the online programming assignments, and then receive a final grade no less than 60 out of 100. The final grade is calculated by $$G = (G_{mid-term}\times 40\% + G_{final}\times 60\%)$$ if $$G_{mid-term} > G_{final}$$, or $$G_{final}$$ will be taken as the final grade $$G$$. Here $$G_{mid-term}$$ and $$G_{final}$$ are the student's scores of the mid-term and the final exams, respectively.

The problem is that different exams have different grading sheets. Your job is to write a program to merge all the grading sheets into one.

### Input Specification:

Each input file contains one test case. For each case, the first line gives three positive integers: P , the number of students having done the online programming assignments; M, the number of students on the mid-term list; and N, the number of students on the final exam list. All the numbers are no more than 10,000.

Then three blocks follow. The first block contains P online programming scores $$G_p$$'s; the second one contains M mid-term scores $$G_{mid-term}$$'s; and the last one contains N final exam scores $$G_{final}$$'s. Each score occupies a line with the format: `StudentID Score`, where `StudentID` is a string of no more than 20 English letters and digits, and `Score` is a nonnegative integer (the maximum score of the online programming is 900, and that of the mid-term and final exams is 100).

### Output Specification:

For each case, print the list of students who are qualified for certificates. Each student occupies a line with the format:

`StudentID` $$G_p$$ $$G_{mid-term}$$ $$G_{final}$$ $$G$$

If some score does not exist, output "$$-1$$" instead. The output must be sorted in descending order of their final grades ($$G$$ must be rounded up to an integer). If there is a tie, output in ascending order of their `StudentID`'s. It is guaranteed that the `StudentID`'s are all distinct, and there is at least one qullified student.

### Sample Input:
```in
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
```

### Sample Output:
```out
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
```

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct node {
	bool isqulified;
	string id;
	int gp, gm, gf, g;
};

bool cmp(node a, node b) {
	return a.g != b.g ? a.g > b.g : a.id < b.id;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	int p, m, n, cnt = 0, score;
	string tid;
	cin >> p >> m >> n;
	vector<node> v(1);
	map<string, int> mp;
	for (int i = 0; i < p; i++) {
		cin >> tid >> score;
		if (score >= 200) {
			v.push_back(node{ true, tid, score, -1, -1 });
			mp[tid] = ++cnt;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> tid >> score;
		if (mp[tid]) {
			v[mp[tid]].gm = score;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> tid >> score;
		if (mp[tid]) {
			v[mp[tid]].gf = score;
		}
	}
	for (auto& it : v) {
		it.g = it.gm > it.gf ? int(it.gm * 0.4 + it.gf * 0.6 + 0.5) : it.gf;
		it.isqulified = it.g >= 60 ? true : false;
	}
	sort(v.begin(), v.end(), cmp);
	for (auto it : v) {
		if (it.isqulified) {
			cout << it.id << " " << it.gp << " " << it.gm << " " << it.gf << " " << it.g << endl;
		}
	}
	return 0;
}
```