#include <iostream>
#include <vector>
#define maxsize 40
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  vector<int> cnt(maxsize);
  vector<int> out;
  int n;
  cin >> n;
  for (int i = 0, integer; i < n; i++) {
    int temp = 0;
    cin >> integer;
    while (integer > 0) {
      temp += integer % 10;
      integer /= 10;
    }
    cnt[temp]++;
  }
  for (int i = 0; i < maxsize; i++) {
    if (cnt[i]) {
      out.push_back(i);
    }
  }
  cout << out.size() << endl;
  auto it = out.begin();
  cout << *it++;
  while (it != out.end()) cout << ' ' << *it++;
  return 0;
}