#include <stdio.h>
#include <string.h>

int caculator(char* str, int& len);
int Reverse(char* str, int len);

int main() {
  char str[30] = {0};
  scanf("%s", str);  //输入
  int len = strlen(str);
  printf("%s", caculator(str, len) ? "Yes\n" : "No\n");  //输出
  printf(str);
}

int caculator(char* str, int& len) {
  int in = 0, count[10] = {0};
  Reverse(str, len);
  for (int i = 0; i < len; i++) {  //加法器
    int temp = str[i] - '0';
    count[temp]++;
    str[i] = temp * 2 % 10 + in + '0';
    if (temp * 2 >= 10)
      in = 1;
    else
      in = 0;
  }
  if (in) {
    str[len++] = in + '0';
    str[len] = '\0';
    Reverse(str, len);
    return 0;
  }
  Reverse(str, len);
  for (int i = 0; i < len; i++) {  //检验
    int temp = str[i] - '0';
    count[temp]--;
  }
  for (int i = 0; i < 10; i++) {
    if (count[i] != 0) return 0;
  }

  return 1;
}

int Reverse(char* str, int len) {  //字符串反转
  len--;
  for (int i = 0; i < len; i++, len--) {
    int temp = str[i];
    str[i] = str[len];
    str[len] = temp;
  }
  return 0;
}