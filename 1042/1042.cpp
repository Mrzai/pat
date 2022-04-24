#include <stdio.h>
#include <string.h>

int add(char* str, int i);
int shuffling(int* temp, int* sort, int times);

int main() {
  int times = 0, temp[54] = {0}, sort[54] = {0};
  char poker[54][4] = {0};
  for (int i = 0; i < 54; i++) {
    temp[i] = i;
    int temp = i % 13;
    switch (i / 13) {
      case 0:
        strcpy(poker[i], "S");
        add(poker[i], temp + 1);
        break;
      case 1:
        strcpy(poker[i], "H");
        add(poker[i], temp + 1);
        break;
      case 2:
        strcpy(poker[i], "C");
        add(poker[i], temp + 1);
        break;
      case 3:
        strcpy(poker[i], "D");
        add(poker[i], temp + 1);
        break;
      case 4:
        strcpy(poker[i], "J");
        add(poker[i], temp + 1);
        break;
    }
  }
  scanf("%d", &times);
  for (int i = 0; i < 54; i++) {
    scanf("%d", sort + i);
    sort[i]--;
  }
  shuffling(temp, sort, times);
  for (int i = 0; i < 54; i++) {
    if (i != 0) putchar(' ');
    printf("%s", poker[temp[i]]);
  }
  return 0;
}

int add(char* str, int i) {
  if (i >= 10) {
    int a = i / 10, b = i % 10;
    str[1] = a + '0';
    str[2] = b + '0';
    str[3] = '\0';
  } else {
    str[1] = i + '0';
    str[2] = '\0';
  }
  return 0;
}

int shuffling(int* temp, int* sort, int times) {
  int test[54] = {0};
  while (times--) {
    for (int i = 0; i < 54; i++) {
      test[sort[i]] = temp[i];
    }
    for (int i = 0; i < 54; i++) {
      temp[i] = test[i];
    }
  }
  return 0;
}