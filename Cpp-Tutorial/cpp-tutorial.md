
### 输出hello world
```c++
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << "hello world!" << n + 1 << endl;
    return 0;
}
```

### 头文件
```c++
#include <cmath> // 相当于C语⾔言⾥里里⾯面的#include <math.h> #include <cstdio> // 相当于C语⾔言⾥里里⾯面的#include <stdio.h> #include <cctype> // 相当于C语⾔言⾥里里⾯面的#include <ctype.h> #include <cstring> // 相当于C语⾔言⾥里里⾯面的#include <string.h>
```

### 变量声明
1. C语⾔言的变量量声明⼀一般都在函数的开头，但是C++在⾸首次使⽤用变量量之前声明即可
2. ⼀一般C语⾔言⾥里里⾯面会在 for 循环的外⾯面定义 i 变量量，但是C++⾥里里⾯面可以在 for 循环内 部定义
3. 在 for 循环⾥里里⾯面定义的局部变量量，在循环外⾯面就失效
```c++
    int m;
    cin >> m;
    for (int i = 0; i < n; i++) {  // 这个i是局部变量，只在for循环⾥面有用
        cout << i;
    }
    for (int i = 0; i < m; i++) {  // 又可以定义一个i，不冲突
        cout << i + 2;
    }
```