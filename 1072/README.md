# 1072 Gas Station
A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.

Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: $$N$$ ($$\le 10^3$$), the total number of houses; $$M$$ ($$\le 10$$), the total number of the candidate locations for the gas stations; $$K$$ ($$\le 10^4$$), the number of roads connecting the houses and the gas stations; and $$D_S$$, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to $$N$$, and all the candidate locations are numbered from `G`1 to `G`$$M$$.

Then $$K$$ lines follow, each describes a road in the format
```
P1 P2 Dist
```
where `P1` and `P2` are the two ends of a road which can be either house numbers or gas station numbers, and `Dist` is the integer length of the road.

### Output Specification:

For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output `No Solution`.

### Sample Input 1:
```in
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
```

### Sample Output 1:
```out
G1
2.0 3.3
```

### Sample Input 2:
```in
2 1 2 10
1 G1 9
2 G1 20
```

### Sample Output 2:
```out
No Solution
```

```cpp
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#define MAX 99999999
using namespace std;

struct node {
  string id;
  double mindist, avgdist;
};

void dijkstra(vector<vector<int>> &edge, vector<node> &temp, int n, int ds,
              int root) {
  vector<bool> visited(edge.size(), false);
  vector<int> dist(edge.size());
  double mindist = MAX, avgdist = 0;
  for (int i = 1; i < edge.size(); i++) {
    dist[i] = edge[root][i];
  }
  visited[root] = true;
  for (int i = 2; i < edge.size(); i++) {
    int u = 0, min = MAX;
    for (int j = 1; j < edge.size(); j++) {
      if (dist[j] < min && !visited[j]) {
        u = j;
        min = dist[j];
      }
    }
    visited[u] = true;
    for (int j = 1; j < edge.size(); j++) {
      dist[j] = dist[u] + edge[u][j] < dist[j] ? dist[u] + edge[u][j] : dist[j];
    }
  }
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > ds) {
      flag = false;
      break;
    }
    avgdist += dist[i];
    mindist = dist[i] < mindist ? dist[i] : mindist;
  }
  if (flag) {
    string id = "G" + to_string(root - n);
    temp.push_back({id, mindist, avgdist / n});
  }
}

bool cmp(node a, node b) {
  if (a.mindist != b.mindist) {
    return a.mindist > b.mindist;
  } else if (a.avgdist != b.mindist) {
    return a.avgdist < b.avgdist;
  } else
    return a.id < b.id;
}

int main() {
  int n, m, k, ds;
  cin >> n >> m >> k >> ds;
  vector<vector<int>> edge(n + m + 1, vector<int>(n + m + 1, MAX));
  for (int i = 0, dist; i < k; i++) {
    string s1, s2;
    cin >> s1 >> s2 >> dist;
    int x = s1[0] == 'G' ? stoi(s1.substr(1)) + n : stoi(s1);
    int y = s2[0] == 'G' ? stoi(s2.substr(1)) + n : stoi(s2);
    edge[x][y] = edge[y][x] = dist;
  }

  vector<node> temp;
  for (int i = n + 1; i < edge.size(); i++) {
    dijkstra(edge, temp, n, ds, i);
  }

  if (temp.size()) {
    sort(temp.begin(), temp.end(), cmp);
    cout << temp[0].id << endl;
    printf("%.1f %.1f\n", temp[0].mindist, temp[0].avgdist);
  } else {
    cout << "No Solution" << endl;
  }

  return 0;
}
```