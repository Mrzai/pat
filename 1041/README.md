# 1041 Be Unique
Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from [$$1, 10^4$$]. The first one who bets on a unique number wins. For example, if there are 7 people betting on { 5 31 5 88 67 88 17 }, then the second one who bets on 31 wins.

### Input Specification:

Each input file contains one test case. Each case contains a line which begins with a positive integer $$N$$ ($$\le 10^5$$) and then followed by $$N$$ bets. The numbers are separated by a space.

### Output Specification:

For each test case, print the winning number in a line. If there is no winner, print `None` instead.

### Sample Input 1:
```in
7 5 31 5 88 67 88 17
```

### Sample Output 1:
```out
31
```

### Sample Input 2:
```in
5 888 666 666 888 888
```

### Sample Output 2:
```out
None
```

```cpp
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
```