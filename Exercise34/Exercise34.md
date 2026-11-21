# Exercise 34

> What will be the output of the following program?

```
#include <iostream>
using namespace std;
int main()
{
int a = 10, *pa, &ra;
pa = &a;
ra = a;
cout << "a=" << ra;
return 0;
}
```

```
A. 10
B. No output
C. Compile error
D. Runtime error
```

#### The answer is C
&ra must be assign a value as it is defined, but that isnt the case here, so it will throw an error.