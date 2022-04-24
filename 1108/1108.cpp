#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int num, k = 0;
  double count = 0, temp;
  cin >> num;

  while (num--) {
    int flag = 0;
    char s[50], t[50];
    cin >> s;
    sscanf(s, "%lf", &temp);
    sprintf(t, "%.2f", temp);

    for (int i = 0; i < strlen(s); i++) {
      if (s[i] != t[i]) {
        flag = 1;
        break;
      }
    }

    if (flag || temp < -1000 || temp > 1000) {
      cout << "ERROR: " << s << " is not a legal number" << endl;
      continue;
    }
    count += temp;
    k++;
  }

  if (k > 1)
    printf("The average of %d numbers is %.2lf", k, count / k);
  else if (k == 1)
    printf("The average of 1 number is %.2lf", count);
  else
    printf("The average of 0 numbers is Undefined");
  return 0;
}
