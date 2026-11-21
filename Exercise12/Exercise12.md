# Exercise 12

> code snippet:
```
#include<stdio.h>
int main()
{
char *str;
str = "%d\n";
str++;
str++;
printf(str-2, 300);
return 0;
}
```

```
What will be the output of the program?
A. No output
B. 30
C. 3
D. 300
```

#### The answer is D
The code will initialize a Cstring str = "&d\n", increase the pointer to the first element (str) by 2, then pass str - 2 to printf, which prints out the number 300 with the format int, then a new line.
