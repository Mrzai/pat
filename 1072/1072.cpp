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