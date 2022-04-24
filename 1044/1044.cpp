#include <iostream>
#include <vector>
#define INT_MAX 0x7fffffff
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  vector<int> chain;
  int num, count;
  cin >> num >> count;
  chain.resize(num);
  for (int i = 0; i < num; i++) {
    cin >> chain[i];
  }
  vector<int> s;
  int min = INT_MAX, amount = 0;
  for (int i = 0, j = 0; i < num; i++) {
    for (; j < num; j++) {
      amount += chain[j];
      if (amount >= count && amount == min) {
        s.push_back(i);
        s.push_back(j);
        break;
      } else if (amount >= count && amount < min) {
        min = amount;
        s.clear();
        s.push_back(i);
        s.push_back(j);
        break;
      } else if (amount >= count || j == num - 1) {
        break;
      }
    }
    if (i == j && chain[i] >= count) {
      amount -= chain[i];
      j++;
    } else
      amount -= chain[i] + chain[j];
  }
  for (int i = 0; i < s.size() - 1; i += 2) {
    cout << s[i] + 1 << '-' << s[i + 1] + 1 << endl;
  }
  return 0;
}