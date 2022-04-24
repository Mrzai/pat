# 1062 Talent and Virtue
About 900 years ago, a Chinese philosopher Sima Guang wrote a history book in which he talked about people's talent and virtue. According to his theory, a man being outstanding in both talent and virtue must be a "sage（圣人）"; being less excellent but with one's virtue outweighs talent can be called a "nobleman（君子）"; being good in neither is a "fool man（愚人）"; yet a fool man is better than a "small man（小人）" who prefers talent than virtue.

Now given the grades of talent and virtue of a group of people, you are supposed to rank them according to Sima Guang's theory.

### Input Specification:

Each input file contains one test case. Each case first gives 3 positive integers in a line: $$N$$ ($$\le 10^5$$), the total number of people to be ranked; $$L$$ ($$\ge 60$$), the lower bound of the qualified grades -- that is, only the ones whose grades of talent and virtue are both not below this line will be ranked; and $$H$$ ($$<100$$), the higher line of qualification -- that is, those with both grades not below this line are considered as the "sages", and will be ranked in non-increasing order according to their total grades. Those with talent grades below $$H$$ but virtue grades not are considered as the "noblemen", and are also ranked in non-increasing order according to their total grades, but they are listed after the "sages". Those with both grades below $$H$$, but with virtue not lower than talent are considered as the "fool men". They are ranked in the same way but after the "noblemen". The rest of people whose grades both pass the $$L$$ line are ranked after the "fool men".

Then $$N$$ lines follow, each gives the information of a person in the format:
```
ID_Number Virtue_Grade Talent_Grade
```
where `ID_Number` is an 8-digit number, and both grades are integers in [0, 100]. All the numbers are separated by a space.

### Output Specification:

The first line of output must give $$M$$ ($$\le N$$), the total number of people that are actually ranked. Then $$M$$ lines follow, each gives the information of a person in the same format as the input, according to the ranking rules. If there is a tie of the total grade, they must be ranked with respect to their virtue grades in non-increasing order. If there is still a tie, then output in increasing order of their ID's.

### Sample Input:
```in
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
```

### Sample Output:
```out
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
```


```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct stu {
	int id, v, t;
};

bool cmp(stu a, stu b) {
	if (a.t + a.v != b.t + b.v)
		return a.t + a.v > b.t + b.v;
	else if (a.v != b.v)
		return a.v > b.v;
	else
		return a.id < b.id;
}
int main() {
	vector<stu> sages, noblemen, foolmen, others;
	int n, l, h;
	cin >> n >> l >> h;
	for (int i = 0; i < n; i++) {
		int id_temp, v_temp, t_temp;
		scanf("%d %d %d", &id_temp, &v_temp, &t_temp);
		if (v_temp < l || t_temp < l)
			continue;
		stu temp = { id_temp, v_temp, t_temp };
		if (v_temp >= h && t_temp >= h)
			sages.push_back(temp);
		else if (v_temp >= h && t_temp < h)
			noblemen.push_back(temp);
		else if (v_temp < h && t_temp < h && v_temp >= t_temp)
			foolmen.push_back(temp);
		else
			others.push_back(temp);
	}
	cout << sages.size() + noblemen.size() + foolmen.size() + others.size() << endl;

	sort(sages.begin(), sages.end(), cmp);
	for (int i = 0; i < sages.size(); i++) { printf("%d %d %d\n", sages[i].id, sages[i].v, sages[i].t); }

	sort(noblemen.begin(), noblemen.end(), cmp);
	for (int i = 0; i < noblemen.size(); i++) { printf("%d %d %d\n", noblemen[i].id, noblemen[i].v, noblemen[i].t); }

	sort(foolmen.begin(), foolmen.end(), cmp);
	for (int i = 0; i < foolmen.size(); i++) { printf("%d %d %d\n", foolmen[i].id, foolmen[i].v, foolmen[i].t); }

	sort(others.begin(), others.end(), cmp);
	for (int i = 0; i < others.size(); i++) { printf("%d %d %d\n", others[i].id, others[i].v, others[i].t); }

	return 0;
}
```