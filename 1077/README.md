# 1077 Kuchiguse
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

- Itai nyan~ (It hurts, nyan~)

- Ninjin wa iyada nyan~ (I hate carrots, nyan~)

Now given a few lines spoken by the same character, can you find her Kuchiguse?

### Input Specification:

Each input file contains one test case. For each case, the first line is an integer $$N$$ ($$2\le N\le 100$$). Following are $$N$$ file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.

### Output Specification:

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all $$N$$ lines. If there is no such suffix, write `nai`.

### Sample Input 1:
```in
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
```

### Sample Output 1:
```out
nyan~
```

### Sample Input 2:
```in
3
Itai!
Ninjinnwaiyada T_T
T_T
```

### Sample Output 2:
```out
nai
```


```cpp
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
```