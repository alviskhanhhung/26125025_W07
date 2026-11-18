# Exercise 06

> code snippet:
```
1. int *p , *q , v , nom[5];
2. p = &v;
3. *p = 12;
4. q = p;
5. nom[0] = *q;
6. p = nom;
7. p++;
8. nom[2] = 12;
9. *p = 13;
10. *q = 10;
11. v = 11;
12. *(p+3) = 16;
13. p = &nom[3];
14. *p = 10;
15. p--;
```

What are the last values of *p , *q , v and nom ?

> Value tracking:
```
1->5: q = p = address of v, nom[0] (or *(nom)) = *q = *p = v = 12
6: p = nom (*p = nom[0])
7: p = nom+1 (*p = nom[1], which has garbage value at this point)
8: nom[2] = 12
9: *p = nom[1] = 13
10: *q = 10
11: v = *q = 11
12: *(p+3) = nom[4] = 16
13: p = address of nom[3] (equivalent to p+=2)
14: *p = nom[3] = 10
15: p-- (p = (nom+2) = &nom[2])
```

#### Final value: *p = 12, *q = 11, v = 11, nom is an array of {12, 13, 12, 10, 16}.

Note that I answer for nom and last value of array nom[5], as I don't know which one you are referring to as last value of nom.