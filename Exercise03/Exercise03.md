# Exercise 03

> code snippet:
```
int *a = new int;
int *b = new int;
*a = 2;
b = a;
cout << *a << endl;
cout << *b << endl;
delete a;
delete b;
```
>Example output:
``` 
2
2
free(): double free detected in tcache 2
Aborted (core dumped)
```
Note that this code may run normally with a warning, but there is a memory leak hidden inside. When initializing new array using a pointer, you are practically assigning the pointer points to the first element of the array. 

Then on the 4th line of the snippet, you assign the value of pointer a to pointer b, which means that you have lost access to the array that b points to initially, without freeing it, causing memory leak.

Simultaneously, by deleting a and b, you are freeing the space that a points to and the space that b points to (which is the same thing as the prior one), causing double free error.