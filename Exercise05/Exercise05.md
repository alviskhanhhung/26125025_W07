Exercise 05

> code snippet:

```
int v = 8, *r, *s;
int *p;
int q = 100;
p = &q;
r = p;
*p = 20;
p = new int;
*r = 30;
q = v;
s = p;
*s = 50;

What are the last values of *p , q , *r , v and *s ?

> Value tracking:
```
1->5: v = 8, q = 100, p = address of q, r = p (= address of q)
6: q = 20
7: p -> new int (with no initial value)
8: q = 30
9: q = v = 8
10: s = p (s and p points to the int at line 7)
11: the value s points to is assigned to be 50, which means *s = *p = 50

```
### Final value: *p = 50, q = 8, *r = 8, v = 8, *s = 50. 

```