#include <algorithm>
#include <iostream>
#define maxsize 3000
using namespace std;

struct student {
  int id;
  int best;
  int score[4];
  int rank[4];
};
student s[maxsize];
int exist[1000000] = {0}, flag = -1;
bool cmp(student a, student b) { return a.score[flag] > b.score[flag]; }

int main() {
  int n, m;
  char c[4] = {'A', 'C', 'M', 'E'};
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> s[i].id >> s[i].score[1] >> s[i].score[2] >> s[i].score[3];
    s[i].score[0] = (s[i].score[1] + s[i].score[2] + s[i].score[3]) / 3;
  }

  for (flag = 0; flag < 4; flag++) {
    sort(s, s + n, cmp);
    s[0].rank[flag] = 1;
    for (int i = 1; i < n; i++) {
      if (s[i].score[flag] == s[i - 1].score[flag])
        s[i].rank[flag] = s[i - 1].rank[flag];
      else
        s[i].rank[flag] = i + 1;
    }
  }

  for (int i = 0; i < n; i++) {
    exist[s[i].id] = i + 1;
    s[i].best = 0;
    int min = s[i].rank[0];
    for (int j = 1; j < 4; j++) {
      if (s[i].rank[j] < min) {
        min = s[i].rank[j];
        s[i].best = j;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    int index, temp;
    cin >> index;
    if (!exist[index]) {
      cout << "N/A" << endl;
      continue;
    }
    index = exist[index] - 1;
    cout << s[index].rank[s[index].best] << ' ' << c[s[index].best] << endl;
  }
  return 0;
}
