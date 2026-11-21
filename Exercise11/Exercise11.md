# Exercise 11

> code snippet:
```
#include<stdio.h>
int main()
{
int arr[] = {12, 13, 14, 15, 16};
printf("%d, %d, %d\n", sizeof(arr), sizeof(*arr), sizeof(arr[0]));
return 0;
}
```

```
If the size of integer is 4 bytes, what will be the output of the program?
A. 10, 2, 4
B. 20, 4, 4
C. 16, 2, 2
D. 20, 2, 2
```

#### The answer is B
The sizeof(arr) returns the total size of the array in bytes, which is 5 elements * 4 bytes per element = 20 bytes. The sizeof(*arr) and sizeof(arr[0]) both return the size of the first element of the arraym, which is 4 bytes.