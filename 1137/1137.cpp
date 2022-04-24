#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node {
  bool isqulified;
  string id;
  int gp, gm, gf, g;
};

bool cmp(node a, node b) { return a.g != b.g ? a.g > b.g : a.id < b.id; }

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
      v.push_back(node{true, tid, score, -1, -1});
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
      cout << it.id << " " << it.gp << " " << it.gm << " " << it.gf << " "
           << it.g << endl;
    }
  }
  return 0;
}