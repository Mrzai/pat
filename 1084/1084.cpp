#include <stdio.h>
#include <string.h>
#define maxsize 100

int main() {
  char str1[maxsize] = {0}, str2[maxsize] = {0};
  int worn[maxsize] = {0}, index = 0;

  scanf("%s%s", str1, str2);
  for (int i = 0, j = 0; i < strlen(str1); i++) {
    if (str1[i] == str2[j])
      j++;
    else {
      if (str1[i] >= '0' && str1[i] <= '9')
        index = str1[i] - '0';
      else if (str1[i] >= 'a' && str1[i] <= 'z')
        index = str1[i] - 'a' + 10;
      else if (str1[i] >= 'A' && str1[i] <= 'Z')
        index = str1[i] - 'A' + 10;
      else
        index = 36;
      if (!worn[index]) {
        worn[index] = 1;
        if (index < 10)
          putchar(index + '0');
        else if (index < 36)
          putchar(index - 10 + 'A');
        else if (index == 36)
          putchar('_');
        else
          continue;
      }
    }
  }

  return 0;
}