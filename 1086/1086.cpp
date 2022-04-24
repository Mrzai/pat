#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> pre, in;
void postorder(int root, int low, int high) {
  if (low > high) return;
  static int flag = 0;
  int i = low;
  while (in[i] != pre[root]) i++;
  postorder(root + 1, low, i - 1);
  postorder(root + i - low + 1, i + 1, high);
  if (flag++) cout << ' ';
  cout << pre[root];
}

int main() {
  ios::sync_with_stdio(false);
  int num;
  stack<int> s;
  cin >> num;
  for (int i = 0, k; i < num || !s.empty();) {
    string temp;
    cin >> temp;
    if (temp == "Push") {
      i++;
      cin >> k;
      pre.push_back(k);
      s.push(k);
    } else {
      in.push_back(s.top());
      s.pop();
    }
  }
  postorder(0, 0, num - 1);
  return 0;
}