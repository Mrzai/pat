#include <cstdio>
#include <set>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  set<int> s[51];
  for (int i = 1; i <= n; i++) {
    int num;
    scanf("%d", &num);
    for (int j = 0; j < num; j++) {
      int temp;
      scanf("%d", &temp);
      s[i].insert(temp);
    }
  }
  int q_times;
  scanf("%d", &q_times);
  for (int k = 0; k < q_times; k++) {
    int i, j;
    float cnt = 0;
    scanf("%d %d", &i, &j);
    for (auto it = s[i].begin(); it != s[i].end(); it++) {
      if (s[j].count(*it)) cnt++;
    }
    printf("%.1f%%\n", cnt / (s[i].size() + s[j].size() - cnt) * 100);
  }
  return 0;
}