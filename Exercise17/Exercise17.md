# Exercise 17
> code snippet:
```
int a = 100, b = 200;
int *p = &a, *q = &b;
p = q;
```

```
What will happen in this code?
A. b is assigned to a
B. p now points to b
C. a is assigned to b
D. q now points to a
```

#### The answer is B
*p =  &a means that p is a pointer to a, same goes for *q = &b. assigning p = q means that p now points to the same location as q, which is b.