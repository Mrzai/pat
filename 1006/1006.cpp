#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct record {
  char id[20];
  int si = 86401;
  int sl = 0;
};

int main() {
  int num;
  cin >> num;
  record early, last;
  while (num--) {
    int m = 0, n = 0;
    int ti[3], tl[3];
    char temp[20];
    cin >> temp;
    scanf("%d:%d:%d %d:%d:%d", ti, ti + 1, ti + 2, tl, tl + 1, tl + 2);
    for (int i = 0; i < 3; i++) {
      m = m * 60 + ti[i];
      n = n * 60 + tl[i];
    }
    if (m < early.si) {
      strcpy(early.id, temp);
      early.si = m;
    }
    if (n > last.sl) {
      strcpy(last.id, temp);
      last.sl = n;
    }
  }
  cout << early.id << ' ' << last.id;
}