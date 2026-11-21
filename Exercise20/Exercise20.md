# Exercise 20

> What is the output of this program?

```
#include <iostream>
using namespace std;
int main()
{
char *ptr;
char Str[] = "abcdefg";
ptr = Str;
ptr += 5;
cout << ptr;
return 0;
}
```

```
A. fg
B. cdef
C. defg
D. abcd
```

#### The answer is A
ptr = Str, which means ptr points to the first element of the array Str. ptr += 5, which means ptr points to the 6th element of the array Str. cout << ptr prints out the string starting from the 6th element, which is "fg".