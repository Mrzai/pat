# 1073 Scientific Notation
Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]`.`[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number $$A$$ in scientific notation, you are supposed to print $$A$$ in the conventional notation while keeping all the significant figures.

### Input Specification:

Each input contains one test case. For each case, there is one line containing the real number $$A$$ in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

### Output Specification:

For each test case, print in one line the input number $$A$$ in the conventional notation, with all the significant figures kept, including trailing zeros.

### Sample Input 1:
```in
+1.23400E-03
```

### Sample Output 1:
```out
0.00123400
```

### Sample Input 2:
```in
-1.2E+10
```

### Sample Output 2:
```out
-12000000000
```

```cpp
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
```