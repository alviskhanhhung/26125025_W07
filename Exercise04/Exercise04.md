# Exercise 04

> code snippet:
```
int a = 3;
int *p = &a;
cout << *p << endl;
p = new int(5);
cout << *p << endl;
```
>Example output:
``` 
3
5
```
This code will execute flawlessly, but also comes with memory leak. Because the user forget to delete the pointer after the 2nd print.