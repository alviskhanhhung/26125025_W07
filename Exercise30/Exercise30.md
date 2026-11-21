# Exercise 30

> What will be the output of the following program?

```
#include <iostream>
using namespace std;
int main()
{
int a = 32, *ptr = &a;
char ch = 'A', &cho = ch;
cho += a;
*ptr += ch;
cout << a << ", " << ch << endl;
return 0;
}
```

```
A. 32, A
B. 32, a
C. 129, a
D. 129, A
```

#### The answer is C
cho += a -> cho = 32 + 'A' = a.
ch = 'A', *ptr = a, *ptr += ch -> a = 32 + cho = 129
Hence: a = 129, ch = a 
