#include <stdio.h>
#include <string.h>
#define maxsize 500

int main() {
  char str1[maxsize] = {0}, suffix[maxsize] = {0}, str2[maxsize] = {0};
  int num = 0, k = 0;

  scanf("%d", &num);
  getchar();
  scanf("%[^\n]", str1);
  getchar();
  scanf("%[^\n]", str2);
  for (int i = strlen(str1) - 1, j = strlen(str2) - 1; i >= 0 && j >= 0;
       i--, j--) {
    if (str1[i] == str2[j])
      suffix[k++] = str1[i];
    else
      break;
  }
  for (int i = 0; i < num - 2; i++) {
    k = 0;
    getchar();
    scanf("%[^\n]", str1);
    for (int j = strlen(str1) - 1; j >= 0; j--) {
      if (str1[j] != suffix[k]) break;
      k++;
    }
  }
  suffix[k] = '\0';
  if (k == 0) {
    printf("nai");
    return 0;
  } else
    k--;
  for (int i = 0; i < k; i++, k--) {
    char c = suffix[i];
    suffix[i] = suffix[k];
    suffix[k] = c;
  }
  printf(suffix);
  return 0;
}