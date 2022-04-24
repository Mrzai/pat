#include <stdio.h>
#define max 999999

int main() {
  int fre[10001] = {0}, input[100000] = {0}, min = max, num = 0;
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    scanf("%d", input + i);
    fre[input[i]] += 1;
  }

  for (int i = 1; i <= 10000; i++) {
    if (fre[i] == 1) {
      for (int j = 0; j < num; j++) {
        if ((input[j] == i) && (j < min)) min = j;
      }
    }
  }

  if (min != max)
    printf("%d", input[min]);
  else
    printf("None");
  return 0;
}