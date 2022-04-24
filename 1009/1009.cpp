#include <cstdio>
#include <iostream>
#define maxsize 2001
using namespace std;

int main() {
  int k, count = 0;
  float po[maxsize] = {0}, out[maxsize] = {0};
  scanf("%d", &k);
  while (k--) {
    int ex;
    float re;
    scanf("%d %f", &ex, &re);
    po[ex] += re;
  }
  scanf("%d", &k);
  while (k--) {
    int ex;
    float re;
    scanf("%d %f", &ex, &re);
    for (int i = 0; i <= 1000; i++) {
      if (po[i] != 0) {
        out[i + ex] += re * po[i];
      }
    }
  }
  for (int i = maxsize - 1; i >= 0; i--) {
    if (out[i] != 0) {
      count++;
    }
  }
  cout << count;
  for (int i = maxsize - 1; i >= 0; i--) {
    if (out[i] != 0) {
      printf(" %d %.1f", i, out[i]);
    }
  }
  return 0;
}