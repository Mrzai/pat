#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct mice {
  int rank = 0, weight;
};

int main() {
  int np, ng;
  cin >> np >> ng;
  vector<mice> v(np);
  vector<int> order(np), temp;

  for (int i = 0; i < np; i++) {
    scanf("%d", &v[i].weight);
  }
  for (int i = 0; i < np; i++) {
    scanf("%d", &order[i]);
  }

  while (true) {
    if (order.size() == 1) {
      v[order[0]].rank = 1;
      break;
    }
    int k = order.size() % ng ? order.size() / ng + 2 : order.size() / ng + 1;
    if (order.size() == 1) k = 1;
    for (int i = 0; i < order.size(); i++) {
      v[order[i]].rank = k;
    }
    for (int i = 0; i < k - 1; i++) {
      int low = i * ng;
      int high = low + ng < order.size() ? low + ng : order.size();
      int maxkey = order[low];
      int maxw = v[order[low++]].weight;
      while (low < high) {
        if (v[order[low]].weight > maxw) {
          maxw = v[order[low]].weight;
          maxkey = order[low];
        }
        low++;
      }
      temp.push_back(maxkey);
    }
    order.assign(temp.begin(), temp.end());
    temp.clear();
  }

  for (int i = 0; i < np; i++) {
    if (i) putchar(' ');
    printf("%d", v[i].rank);
  }
  return 0;
}