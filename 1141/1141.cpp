#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct node {
  string id;
  int cnt;
  double score;
};

void tolower(string& s) {
  for (int i = 0; i < s.size(); i++) {
    s[i] = s[i] | 32;
  }
}

bool cmp(node a, node b) {
  if (a.score != b.score)
    return a.score > b.score;
  else if (a.cnt != b.cnt)
    return a.cnt < b.cnt;
  else
    return a.id < b.id;
}

int main() {
  ios::sync_with_stdio(false);
  int n, cnt = 1;
  double score;
  cin >> n;
  string id, school;
  vector<node> v(1);
  unordered_map<string, int> m;
  for (int i = 0; i < n; i++) {
    cin >> id >> score >> school;
    tolower(school);
    if (!m[school]) {
      v.push_back(node{school});
      m[school] = cnt++;
    }
    v[m[school]].cnt++;
    if (id[0] == 'A')
      v[m[school]].score += score;
    else if (id[0] == 'B')
      v[m[school]].score += score / 1.5;
    else
      v[m[school]].score += score * 1.5;
  }
  for (auto& it : v) {
    it.score = int(it.score);
  }
  sort(v.begin() + 1, v.end(), cmp);
  cout << v.size() - 1 << endl;
  for (int i = 1, temp; i < v.size(); i++) {
    if (i == 1 || v[i].score != v[i - 1].score) {
      cout << i << " " << v[i].id << " " << v[i].score << " " << v[i].cnt
           << endl;
      temp = i;
    } else {
      cout << temp << " " << v[i].id << " " << v[i].score << " " << v[i].cnt
           << endl;
    }
  }
  return 0;
}