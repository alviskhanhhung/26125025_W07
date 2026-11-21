# Exercise 35

> What will be the output?

```
#include<stdio.h>
int main()
{
int a[] = { 1, 2, 3, 4, 5} ;
int *ptr;
ptr = a;
printf(" %d ", *( ptr + 1) );
return 0;
}
```

#### The output will be 2.
ptr = a means that ptr points to the first value of array a. *(ptr + 1) will print out a[1] = 2, %d tell the console to print it out as integer.