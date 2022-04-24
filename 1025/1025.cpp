#include <algorithm>
#include <iostream>
#define maxsize 30000
using namespace std;

struct test {
  string id;
  int local;
  int score;
  int rank;
};
bool cmp(test a, test b) {
  return a.score != b.score ? a.score > b.score : a.id < b.id;
}
int main() {
  test t[maxsize];
  int n, k, index = 0;
  cin >> n;

  for (int i = 0, j; i < n; i++) {
    cin >> k;
    for (j = 0; j < k; j++) {
      t[index].local = i + 1;
      cin >> t[index].id;
      cin >> t[index++].score;
    }
    sort(t + index - j, t + index, cmp);
    j = index - j;
    for (int k = 1, flag; j < index; j++, k++) {
      if (k == 1 || t[j - 1].score != t[j].score) {
        t[j].rank = k;
      } else
        t[j].rank = t[j - 1].rank;
    }
  }

  sort(t, t + index, cmp);
  cout << index << endl;
  for (int i = 0, flag; i < index; i++) {
    int final_rank;
    if (i == 0 || t[i - 1].score != t[i].score) {
      flag = i + 1;
      final_rank = i + 1;
    } else
      final_rank = flag;
    cout << t[i].id << " " << final_rank << " " << t[i].local << " "
         << t[i].rank << endl;
  }
  return 0;
}