#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct card {
  string id;
  int score;
};

bool cmp(const card& a, const card& b) {
  return a.score == b.score ? a.id < b.id : a.score > b.score;
}

int main() {
  int n, m;
  string temp;
  cin >> n >> m;
  vector<card> v(n);
  for (int i = 0, score; i < n; i++) {
    cin >> v[i].id >> v[i].score;
  }
  for (int i = 1, type; i <= m; i++) {
    cin >> type >> temp;
    printf("Case %d: %d %s\n", i, type, temp.c_str());
    vector<card> ans;
    if (type == 1) {
      for (auto& it : v) {
        if (it.id[0] == temp[0]) {
          ans.push_back(it);
        }
      }
    } else if (type == 2) {
      int sum = 0, cnt = 0;
      for (auto& it : v) {
        if (it.id.substr(1, 3) == temp) {
          cnt++;
          sum += it.score;
        }
      }
      if (cnt)
        printf("%d %d\n", cnt, sum);
      else
        printf("NA\n");
      continue;
    } else {
      unordered_map<string, int> mp;
      for (auto& it : v) {
        if (it.id.substr(4, 6) == temp) {
          mp[it.id.substr(1, 3)]++;
        }
      }
      for (auto& it : mp) ans.push_back(card{it.first, it.second});
    }
    sort(ans.begin(), ans.end(), cmp);
    if (!ans.size()) printf("NA\n");
    for (auto& it : ans) printf("%s %d\n", it.id.c_str(), it.score);
  }
  return 0;
}