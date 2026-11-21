# Exercise 16
```
Which of the following is illegal?
A. int *ip;
B. string s, *sp = 0;
C. int i; double* dp = &i;
D. int *pi = 0;
```

#### The answer is C. 
dp is a double pointer, so we cannot assign it the address of an int.