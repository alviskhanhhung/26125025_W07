# Exercise 33

> What will be the output of the following program?

```
#include <iostream>
using namespace std;
int main()
{
int arr[] = { 4, 5, 6, 7 };
int* p = (arr + 1);
cout << *arr + 10;
return 0;
}
```

```
A. 12
B. 15
C. 14
D. Error
```

#### The answer is C
*arr is the value of the first element of arr (arr[0]), +10 is 14.