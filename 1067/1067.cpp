#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int num, cnt = 0;
  scanf("%d", &num);
  vector<int> index(num);
  for (int i = 0, temp; i < num; i++) {
    scanf("%d", &temp);
    index[temp] = i;
  }
  for (int i = 1; i < num; i++) {
    if (index[i] != i) {
      while (index[0] != 0) {
        swap(index[0], index[index[0]]);
        cnt++;
      }
      if (index[i] != i) {
        swap(index[0], index[i]);
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}