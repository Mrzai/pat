#include <stdio.h>
#include <string.h>

int main() {
  int num = 0, count = 0, modified[1000] = {0};
  char str1[1000][20] = {0}, str2[1000][20] = {0};
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    scanf("%s", str1 + i);
    scanf("%s", str2 + i);
  }
  for (int i = 0; i < num; i++) {
    int flag = 0;
    for (int j = 0; j < strlen(str2[i]); j++) {
      switch (str2[i][j]) {
        case '1':
          str2[i][j] = '@';
          flag = 1;
          break;
        case '0':
          str2[i][j] = '%';
          flag = 1;
          break;
        case 'l':
          str2[i][j] = 'L';
          flag = 1;
          break;
        case 'O':
          str2[i][j] = 'o';
          flag = 1;
          break;
      }
    }
    if (flag) {
      count++;
      modified[i] = 1;
    }
  }
  if (!count) {
    if (num == 1)
      printf("There is 1 account and no account is modified");
    else
      printf("There are %d accounts and no account is modified", num);
  } else {
    printf("%d\n", count);
    for (int i = 0; count > 0; i++) {
      if (modified[i]) {
        printf("%s %s\n", str1[i], str2[i]);
        count--;
      }
    }
  }
}