#include <stdio.h>
#include <string.h>
#define maxsize 9999

int main() {
  int a, index = 0, i = 0, flag = 0, len;
  char str[maxsize] = {0};
  if (getchar() == '-') {
    putchar('-');
  }
  scanf("%d.%s", &a, str);
  len = (int)strlen(str);
  while (str[i] != 'E') {
    i++;
  }
  str[i++] = '\0';
  if (str[i] == '-') flag = 1;
  for (i++; i < len; i++) {
    index = index * 10 + str[i] - '0';
  }

  if (flag) {
    printf("0.");
    for (int i = 0; i < index - 1; i++) {
      putchar('0');
    }
    printf("%d%s", a, str);
  } else {
    printf("%d", a);
    len = strlen(str);
    if (index < len) {
      for (int i = 0; i < len; i++) {
        if (i == index) putchar('.');
        putchar(str[i]);
      }
    } else if (index == len)
      printf(str);
    else {
      for (int i = 0; i < index; i++) {
        if (i < len)
          putchar(str[i]);
        else
          putchar('0');
      }
    }
  }
  return 0;
}