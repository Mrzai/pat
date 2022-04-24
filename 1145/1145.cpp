#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
  if (x == 1 || x == 0) {
    return false;
  }
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int msize, n, m, cnt = 0;
  cin >> msize >> n >> m;
  while (!isPrime(msize)) msize++;
  vector<int> hashtable(msize);
  for (int i = 0, index; i < n; i++) {
    int k = 0;
    scanf("%d", &index);
    while (k < msize && hashtable[(index + k * k) % msize]) k++;
    if (hashtable[(index + k * k) % msize])
      cout << index << " cannot be inserted." << endl;
    else
      hashtable[(index + k * k) % msize] = index;
  }
  for (int i = 0, index; i < m; i++) {
    scanf("%d", &index);
    for (int k = 0; k <= msize; k++) {
      cnt++;
      if (hashtable[(index + k * k) % msize] == index ||
          !hashtable[(index + k * k) % msize])
        break;
    }
  }
  printf("%.1f", float(cnt) / m);
  return 0;
}