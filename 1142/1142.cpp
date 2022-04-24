#include <iostream>
#include <vector>
using namespace std;

bool isClique(vector<vector<bool>>& edge, vector<int>& temp) {
  bool flag = true;
  for (auto i : temp) {
    for (auto j : temp) {
      if (i != j && !edge[i][j]) {
        flag = false;
        break;
      }
    }
    if (!flag) break;
  }
  return flag;
}

bool isMax(vector<vector<bool>>& edge, vector<int>& temp) {
  bool flag = true;
  vector<bool> visited(edge.size());
  for (auto it : temp) {
    visited[it] = true;
  }
  for (int i = 1; i < edge.size(); i++) {
    if (!visited[i]) {
      auto it = temp.begin();
      while (it != temp.end() && edge[*it][i]) it++;
      if (it == temp.end()) flag = false;
    }
    if (!flag) break;
  }
  return flag;
}

int main() {
  ios::sync_with_stdio(false);
  int nv, ne, k;
  cin >> nv >> ne;
  vector<vector<bool>> edge(nv + 1, vector<bool>(nv + 1));
  for (int i = 0; i < ne; i++) {
    int x, y;
    cin >> x >> y;
    edge[x][y] = edge[y][x] = true;
  }
  cin >> k;
  for (int i = 0, len; i < k; i++) {
    cin >> len;
    vector<int> temp;
    for (int j = 0; j < len; j++) {
      int index;
      cin >> index;
      temp.push_back(index);
    }
    if (isClique(edge, temp))
      cout << (isMax(edge, temp) ? "Yes" : "Not Maximal") << endl;
    else
      cout << "Not a Clique" << endl;
  }
  return 0;
}