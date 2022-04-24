#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void dp(vector<int>& v);

int main() {
  int num;
  vector<int> v;
  cin >> num;
  while (num--) {
    int temp;
    cin >> temp;
    v.push_back(temp);
  }
  dp(v);
  return 0;
}

void dp(vector<int>& v) {
  int cur_num = v[0], max_num = v[0], low = v[0], low_ = v[0], high = v[0],
      high_ = v[0], flag = 1;

  for (int i = 0; i < v.size(); i++) {
    if (v[i] >= 0) {
      flag = 0;
      break;
    }
  }
  for (int i = 1; i < v.size(); i++) {
    if (v[i] > v[i] + cur_num) {
      cur_num = v[i];
      low = v[i];
      high = v[i];
    } else {
      cur_num = cur_num + v[i];
      high = v[i];
    }
    if (cur_num > max_num) {
      max_num = cur_num;
      low_ = low;
      high_ = high;
    }
  }
  if (flag) {
    cout << '0' << ' ' << v[0] << ' ' << v[v.size() - 1] << endl;
    return;
  }
  cout << max_num << ' ' << low_ << ' ' << high_ << endl;
}