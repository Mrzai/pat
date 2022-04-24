#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define maxsize 10010
vector<bool> isprime(maxsize, true);

void initprime() {
  isprime[0] = isprime[1] = false;
  for (int i = 2; i < maxsize; i++) {
    if (isprime[i]) {
      for (int j = i * i; j < maxsize; j += i) isprime[j] = false;
    }
  }
}
int main() {
  int n;
  cin >> n;
  initprime();
  vector<int> v(maxsize, -1);
  string award[5] = {"Mystery Award", "Minion", "Chocolate", "Are you kidding?",
                     "Checked"};
  for (int i = 1, id; i <= n; i++) {
    scanf("%d", &id);
    v[id] = i;
  }
  cin >> n;
  for (int i = 0, id, rank; i < n; i++) {
    scanf("%d", &id);
    rank = v[id];
    if (rank == 1)
      cout << setfill('0') << setw(4) << id << ": " << award[0] << endl;
    else if (rank != -1 && rank != -2 && isprime[rank])
      cout << setfill('0') << setw(4) << id << ": " << award[1] << endl;
    else if (rank != -1 && rank != -2)
      cout << setfill('0') << setw(4) << id << ": " << award[2] << endl;
    else if (rank == -1)
      cout << setfill('0') << setw(4) << id << ": " << award[3] << endl;
    else if (rank == -2)
      cout << setfill('0') << setw(4) << id << ": " << award[4] << endl;
    v[id] = v[id] == -1 ? -1 : -2;
  }
  return 0;
}