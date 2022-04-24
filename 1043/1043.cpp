#include <iostream>
#include <vector>
using namespace std;

bool isMirror = false;
vector<int> pre, post;

void get_post(int low, int high) {
  if (low > high) return;
  int i = low + 1, j = high;
  if (!isMirror) {
    for (; i <= high && pre[i] < pre[low]; i++)
      ;
    for (; j > low && pre[j] >= pre[low]; j--)
      ;
  } else {
    for (; i <= high && pre[i] >= pre[low]; i++)
      ;
    for (; j > low && pre[j] < pre[low]; j--)
      ;
  }
  if (i - j != 1) return;
  get_post(low + 1, i - 1);
  get_post(j + 1, high);
  post.push_back(pre[low]);
}

int main() {
  ios::sync_with_stdio(false);
  int num;
  cin >> num;
  pre.resize(num);
  for (int i = 0; i < num; i++) {
    cin >> pre[i];
  }
  get_post(0, num - 1);
  if (post.size() != num) {
    isMirror = true;
    post.clear();
    get_post(0, num - 1);
  }
  if (post.size() == num) {
    cout << "YES" << endl;
    for (int i = 0; i < num; i++) {
      if (i)
        cout << ' ' << post[i];
      else
        cout << post[i];
    }
  } else
    cout << "NO";
  return 0;
}