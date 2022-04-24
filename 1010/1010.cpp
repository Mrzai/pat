#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int tag, radix, n[2][10] = {0}, out = 0, max[2] = {0};
  string in1, in2;
  cin >> in1 >> in2 >> tag >> radix;

  for (int i = 0; i < in1.size(); i++) {
    if (in1[i] <= '9')
      n[0][i] = in1[i] - '0';
    else
      n[0][i] = in1[i] - 'a' + 10;
    max[0] = n[0][i] > max[0] ? n[0][i] : max[0];
  }

  for (int i = 0; i < in2.size(); i++) {
    if (in2[i] <= '9')
      n[1][i] = in2[i] - '0';
    else
      n[1][i] = in2[i] - 'a' + 10;
    max[1] = n[1][i] > max[1] ? n[1][i] : max[1];
  }

  long long sum = 0, temp;
  for (int i = 0; i < (tag == 1 ? in1.size() : in2.size()); i++) {
    sum = sum * radix + n[tag - 1][i];
  }

  long long low = max[!(tag - 1)] + 1, high = sum > low ? sum : low;
  while (low <= high) {
    temp = 0;
    long long mid = (low + high) / 2;
    for (int j = 0; j < (tag == 1 ? in2.size() : in1.size()); j++) {
      temp = temp * mid + n[!(tag - 1)][j];
    }
    if (temp == sum) {
      cout << mid;
      return 0;
    } else if (temp > sum || temp < 0)
      high = mid - 1;
    else
      low = mid + 1;
  }
  /*
  for (long long i = low; i <= high; i++) {
              temp = 0;
              for (int j = 0; j < (tag == 1 ? in2.size() : in1.size()); j++) {
                      temp = temp * i + n[!(tag - 1)][j];
              }
              if (temp > sum|| temp <0) break;
              if (temp == sum) {
                      cout << i << endl;
                      return 0;
              }
      }
  */
  cout << "Impossible" << endl;
  return 0;
}