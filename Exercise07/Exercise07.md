# Exercise 07

> code snippet:
```
#include<stdio.h>
int main()
{
int *x;
*x=100;
return 0;
}
```

> Point out the compile time error in the program.
```
A. Error: invalid exercise for x
B. Error: suspicious pointer conversion
C. No error
D. None of above
```

#### The answer is C, no error.

However, this code is still unsafe to use in real world, as de-referencing an uninitialized pointer will point to any available memory slot, crashing the program or corrupting the memory silently.