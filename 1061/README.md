# 1061 Dating
Sherlock Holmes received a note with some strange strings: `Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm`. It took him only a minute to figure out that those strange strings are actually referring to the coded time `Thursday 14:04` -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter `D`, representing the 4th day in a week; the second common character is the 5th capital letter `E`, representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from `A` to `N`, respectively); and the English letter shared by the last two strings is `s` at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

### Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

### Output Specification:

For each test case, print the decoded time in one line, in the format `DAY HH:MM`, where `DAY` is a 3-character abbreviation for the days in a week -- that is, `MON` for Monday, `TUE` for Tuesday, `WED` for Wednesday, `THU` for Thursday, `FRI` for Friday, `SAT` for Saturday, and `SUN` for Sunday. It is guaranteed that the result is unique for each case.

### Sample Input:
```in
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
```

### Sample Output:
```out
THU 14:04
```


```cpp
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
```