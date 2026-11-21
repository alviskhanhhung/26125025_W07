# Exercise 32

> What will be the output of the following program?

```
#include <iostream>
using namespace std;
int main()
{
int num[5];
int* p;
p = num;
*p = 10;
p++;
*p = 20;
p = &num[2];
*p = 30;
p = num + 3;
*p = 40;
p = num;
*(p + 4) = 50;
for (int i = 0; i < 5; i++)
cout << num[i] << ", ";
return 0;
}
```

```
A. 10, 20, 30, 40, 50
B. 10, 20, 30, 40, 50,
C. Compile error
D. Runtime error
```

#### The answer is B
The process can be describe as assigning value for num[0] up to num[4] with extra steps.