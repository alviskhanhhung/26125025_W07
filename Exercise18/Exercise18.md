# Exercise 18

> What is the output of this program?

```
#include <iostream>
using namespace std;
int main()
{
int a = 5, b = 10, c = 15;
int *arr[ ] = {&a, &b, &c};
cout << arr[1];
return 0;
}
```

```
A. 5
B. 10
C. 15
D. It will return some random number
```

#### The answer is D                                                                 
It will return some random number because arr[1] is a pointer to the second element of the array, but it is not dereferenced.