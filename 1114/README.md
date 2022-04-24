# 1114 Family Property
This time, you are supposed to help us collect the data for family-owned property. Given each person's family members, and the estate（房产）info under his/her own name, we need to know the size of each family, and the average area and number of sets of their real estate.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer $$N$$ ($$\le 1000$$). Then $$N$$ lines follow, each gives the infomation of a person who owns estate in the format:

`ID` `Father` `Mother` $$k$$ $$Child_1 \cdots Child_k$$ $$M_{estate}$$ `Area`

where `ID` is a unique 4-digit identification number for each person; `Father` and `Mother` are the `ID`'s of this person's parents (if a parent has passed away, `-1` will be given instead); $$k$$ ($$0\le k\le 5$$) is the number of children of this person; $$Child_i$$'s are the `ID`'s of his/her children; $$M_{estate}$$ is the total number of sets of the real estate under his/her name; and `Area` is the total area of his/her estate.

### Output Specification:

For each case, first print in a line the number of families (all the people that are related directly or indirectly are considered in the same family). Then output the family info in the format:

`ID` `M` $$AVG_{sets}$$ $$AVG_{area}$$

where `ID` is the smallest ID in the family; `M` is the total number of family members; $$AVG_{sets}$$ is the average number of sets of their real estate; and $$AVG_{area}$$ is the average area. The average numbers must be accurate up to 3 decimal places. The families must be given in descending order of their average areas, and in ascending order of the ID's if there is a tie.

### Sample Input:
```in
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
```

### Sample Output:
```out
3
8888 1 1.000 1000.000
0001 15 0.600 100.000
5551 4 0.750 100.000
```

```cpp
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define maxsize 10000
using namespace std;
int father[maxsize];

struct node {
	int id;
	float sets, area;
}v[1010];

struct family {
	int id, num;
	float avgs, avga;
};

bool cmp(family a, family b) { 
	return a.avga == b.avga ? a.id < b.id : a.avga > b.avga; 
}

int findfather(int x) {
	while (x != father[x]) {
		x = father[x];
	}
	return x;
}

void Union(int x, int y) {
	int fa = findfather(x);
	int fb = findfather(y);
	if (fa < fb) {
		father[fb] = fa;
	}
	else {
		father[fa] = fb;
	}
}

int main() {
	vector<int> index(maxsize, -1);
	vector<bool> visited(maxsize);
	vector<family> temp;
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < maxsize; i++) {
		father[i] = i;
	}
	for (int i = 0, id, fid, mid, k; i < n; i++) {
		scanf("%d %d %d %d", &id, &fid, &mid, &k);
		v[i].id = id;
		visited[id] = true;
		if (fid != -1) {
			visited[fid] = true;
			Union(id, fid);
		}
		if (mid != -1) { 
			visited[mid] = true;
			Union(id, mid); 
		}
		for (int j = 0, temp; j < k; j++) {
			scanf("%d", &temp);
			visited[temp] = true;
			Union(id, temp);
		}
		scanf("%f %f", &v[i].sets, &v[i].area);
	}
	for (int i = 0; i < n; i++) {
		if (visited[v[i].id]) {
			int fid = findfather(v[i].id);
			if (index[fid] != -1) {
				temp[index[fid]].avgs += v[i].sets;
				temp[index[fid]].avga += v[i].area;
			}
			else {
				index[fid] = temp.size();
				temp.push_back({ fid, 0, v[i].sets, v[i].area });
			}
		}
	}
	for (int i = 0; i < maxsize; i++) {
		if (visited[i]) {
			int fid = findfather(i);
			temp[index[fid]].num++;
		}
	}
	for (auto &it : temp) {
		it.avgs /= it.num;
		it.avga /= it.num;
	}
	sort(temp.begin(), temp.end(), cmp);
	cout << temp.size() << endl;
	for (auto it : temp) {
		printf("%04d %d %.3f %.3f\n", it.id, it.num, it.avgs, it.avga);
	}
	return 0;
}
```