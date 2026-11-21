# Exercise 31

> What will be the output of the following program?

```
#include <iostream>
using namespace std;
int main()
{
const int i = 20;
const int* const ptr = &i;
(*ptr)++;
int j = 15;
ptr = &j;
cout << i;
return 0;
}
```

```
A. 20
B. 21
C. 15
D. Compile error
```

#### The answer is D
it will crash at (*ptr)++, as int i is a const, so it cannot change.