#include <stdio.h>

int main() {
  char s1[100000] = {0}, s2[100000] = {0};
  int hash[256] = {0};

  fgets(s1, 100000, stdin);
  fgets(s2, 100000, stdin);

  for (int i = 0; s2[i] != '\0'; i++) {
    hash[s2[i]] = 1;
  }
  for (int i = 0; s1[i] != '\0'; i++) {
    if (hash[s1[i]]) continue;
    putchar(s1[i]);
  }
  return 0;
}