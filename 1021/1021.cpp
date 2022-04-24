#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define maxsize 10001
vector<vector<int>> v;
set<int> s;
vector<int> temp;
bool visited[maxsize] = {false};
int n, flag, maxheight = 0, d[maxsize] = {0}, edge[maxsize][maxsize] = {0};

void dfs(int node, int height) {
  if (height > maxheight) {
    temp.clear();
    temp.push_back(node);
    maxheight = height;
  } else if (height == maxheight) {
    temp.push_back(node);
  }
  visited[node] = true;
  for (int i = 0; i < v[node].size(); i++) {
    if (!visited[v[node][i]]) {
      dfs(v[node][i], height + 1);
    }
  }
}

int main() {
  cin >> n;
  v.resize(int(n + 1));
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i, 1);
      if (i == 1) {
        if (temp.size() != 0) flag = temp[0];
        for (int i = 0; i < temp.size(); i++) {
          s.insert(temp[i]);
        }
      }
      count++;
    }
  }
  if (count != 1) {
    cout << "Error: " << count << " components" << endl;
    return 0;
  } else {
    temp.clear();
    fill(visited + 1, visited + n + 1, false);
    dfs(flag, 1);
    for (int i = 0; i < temp.size(); i++) {
      s.insert(temp[i]);
    }
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
      cout << *it << endl;
    }
  }
  return 0;
}