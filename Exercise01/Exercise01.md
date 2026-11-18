# Exercise 01

> code snippet:
```
int a = 3;
int *b = &a;
cout << b << endl;
cout << *b << endl;
cout << &b << endl;
cout << a << endl;
cout << &a << endl;
```
>Example output:
``` 
0xadf1bffa5c
3
0xadf1bffa50
3
0xadf1bffa5c
```
The code will print out 5 lines, and there will be no error. On a fundamental level, pointer b will point to the address of (&) a, in other words, the value of b will be the memory address of a. So printing out b will give the address of a, same goes for printing &a (line 5).

Using the de-referencing operation (*b) will print out the value of the memory block which b points to (in this case, it is a), so the output for line 2 and line 4 will be identical.

using the address-of operation on b will just print out the memory location of the pointer b itself.