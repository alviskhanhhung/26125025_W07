# Exercise 19

> What is the output of this program?

```
#include <iostream>
using namespace std;
int main()
{
char arr[20];
int i;
for(i = 0; i < 10; i++)
*(arr + i) = 65 + i;
*(arr + i) = '\0';
cout << arr;
return(0);
}
```

```
A. ABCDEFGHIJ
B. AAAAAAAAAA
C. JJJJJJJJ
D. None of the mentioned
```

#### The answer is A
The code initializes an array of 20 characters, then fills the first 10 elements with the ASCII values of A to J, then adds a null terminator at the end. The output will be an array with the characters A to J.