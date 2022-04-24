#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str1[61] = {0}, str2[61] = {0}, str3[61] = {0}, str4[61] = {0};

  scanf("%s%s%s%s", str1, str2, str3, str4);
  char day[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

  int i = 0;
  for (; i < strlen(str1); i++) {
    if (str1[i] != str2[i]) continue;
    if (str1[i] >= 'A' && str1[i] <= 'N') {
      printf("%s ", day[str1[i] - 'A']);
      break;
    }
  }

  for (++i; i < strlen(str1); i++) {
    if (str1[i] != str2[i]) continue;
    if (str1[i] >= 'A' && str1[i] <= 'N') {
      printf("%d:", str1[i] - 'A' + 10);
      break;
    }
    if (str1[i] >= '0' && str1[i] <= '9') {
      printf("%02d:", str1[i] - '0');
      break;
    }
  }

  for (i = 0; i < strlen(str3); i++) {
    if (str3[i] != str4[i]) continue;
    if ((str3[i] >= 'a' && str3[i] <= 'z') ||
        (str3[i] >= 'A' && str3[i] <= 'Z')) {
      printf("%02d", i);
      break;
    }
  }

  return 0;
}