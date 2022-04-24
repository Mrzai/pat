#include <cstdio>
#include <iostream>
#define maxsize 1001
using namespace std;

int main() {
  int k, flag = 0, count = 0;
  float po[maxsize] = {0};
  scanf("%d", &k);
  while (k--) {
    int ex;
    float re;
    scanf("%d %f", &ex, &re);
    // if (po[ex] == 0.0) count++;
    po[ex] += re;
  }
  scanf("%d", &k);
  while (k--) {
    int ex;
    float re;
    scanf("%d %f", &ex, &re);
    // if (po[ex] == 0.0) count++;
    po[ex] += re;
  }
  for (int i = 1000; i >= 0; i--) {
    if (po[i] != 0) {
      count++;
    }
  }
  cout << count;
  for (int i = 1000; i >= 0; i--) {
    if (po[i] != 0.0) {
      printf(" %d %.1f", i, po[i]);
    }
  }
  return 0;
}