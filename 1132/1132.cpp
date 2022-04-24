#include <iostream>
#include <string>
using namespace std;

int main() {
  int z;
  string input;
  cin >> z;
  while (z--) {
    cin >> input;
    string left = input.substr(0, input.size() / 2);
    string right = input.substr(input.size() / 2);
    if (stoi(right) && stoi(input) % (stoi(left) * stoi(right)) == 0) {
      cout << "Yes" << endl;
    } else
      cout << "No" << endl;
  }
  return 0;
}