#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      vector<int> what(n + 1, 1), lie;
      what[i] = what[j] = -1;
      for (int k = 1; k <= n; k++) {
        if (what[abs(v[k])] * v[k] < 0) {
          lie.push_back(k);
        }
      }
      if (lie.size() == 2 && what[lie[0]] + what[lie[1]] == 0) {
        cout << i << " " << j;
        return 0;
      }
    }
  }
  cout << "No Solution";
  return 0;
}