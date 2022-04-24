#include <stdio.h>
#include <string.h>

int str2num(char* str);
int num2str(char* str, int num);
int Max_sort(char* input);
int Min_sort(char* input);

int main() {
  char input[5] = {0}, temp[5] = {0};
  int num = 0;

  scanf("%s", input);
  num = str2num(input);
  num2str(input, num);

  do {
    num2str(temp, num);
    Max_sort(input);
    Min_sort(temp);
    printf("%s - %s = ", input, temp);
    num = str2num(input) - str2num(temp);
    num2str(input, num);
    printf("%s\n", input);

  } while (num != 6174 && num != 0);

  return 0;
}

int str2num(char* str) {
  int num = 0;
  for (int i = 0; i < strlen(str); i++) {
    num = num * 10 + (str[i] - '0');
  }
  return num;
}

int num2str(char* str, int num) {
  for (int i = 3; i >= 0; i--) {
    str[i] = num % 10 + '0';
    num /= 10;
  }
  str[4] = '\0';
  return 0;
}

int Max_sort(char* input) {
  for (int i = 0; i < 3; i++) {
    for (int j = 3; j > i; j--) {
      if (input[j] > input[j - 1]) {
        char temp = input[j];
        input[j] = input[j - 1];
        input[j - 1] = temp;
      }
    }
  }
  return 0;
}

int Min_sort(char* input) {
  for (int i = 0; i < 3; i++) {
    for (int j = 3; j > i; j--) {
      if (input[j] < input[j - 1]) {
        char temp = input[j];
        input[j] = input[j - 1];
        input[j - 1] = temp;
      }
    }
  }
  return 0;
}