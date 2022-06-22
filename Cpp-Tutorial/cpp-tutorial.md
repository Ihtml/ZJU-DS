
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

### bool变量
直接赋值一个数字给 bool 变量也可,它会自动根据 int 值是不是零来决定 给 bool 变量赋值 true 还是 false
```c++
bool flag = true;
bool flag2 = -2; // flag2为true
bool flag3 = 0;  // flag3为false
```

### const常量
c语言用#define定义常量，C++用const定义常量，可以定义常量的类型
```c++
#define MAXSIZE 10
const int a = 99999999;
```

### string类
string只能用cin和cout处理，无法用scanf和printf处理。
用cin读入字符串的时候，是以空格为分隔符的，如果要读入一整行的字符串，就用**getline**
```c++
string s = "hello world"; // 赋值字符串串
string s2 = s;
string s3 = s + s2; // 字符串串拼接直接⽤用+号就可以 string s4;
cin >> s4; // 读⼊入字符串串
cout << s; // 输出字符串串

string s; // 定义一个空字符串s
getline(cin, s); // 读取⼀行的字符串串，包括空格 
cout << s.length(); // 输出字符串s的长度

// substr 截取某个字符串的子串
string s2 = s.substr(4); // 从下标4开始截取一直到结束
string s3 = s.substr(5, 3); // 从下标5开始, 3个字符
```

### struct
定义好结构体后，要使用的时候，C++可以省略关键字struct
```c++
struct stu {
    int grade;
    float score;
}
struct stu arr1[10];  // c语言写法
stu arr2[10];  // C++写法
```

### 引用&
C++的引用是在变量名前加一个&符号，表示对传入的原变量进行操作
```c++
    void func(int &a){  // 传入的是n的引用，相当于直接对n进行操作
        a = 99;
    }
    int main() {
        int n = 0;
        func(n); // n由0变成了99
    }

    void func(int a) {  // 传入的是0这个值，不会改变main函数中n的值
        a = 99;
    }
    int main() {
        int n = 0;
        func(n);  // 并不会改变n的值，n还是0
    }
```

### 动态数组vector矢量
```c++
#include <iostream>
using namespace std;
int main(){
    vector<int> v1; // 定义的时候不用分配大小
    cout << v1.size();  // 输出vector v1的大小, 此处应该为0
    return 0;
}

//  vector 可以一开始不定义大小，之后用 resize ⽅法分配⼤小，也可以一开始就定义⼤小，之后还可以对它插⼊删除动态改变它的⼤小~⽽而且不管在 main 函数⾥里还是在全局中定义，它都能够直接将所有 的值初始化为0(不用显式地写出来，默认就是所有的元素为0)
vector<int> v(10); // 直接定义长度为10的int数组  默认10个元素都是0

vector<int> v1;
v1.resize(8);

vector<int> v3(100, 9); // 把长度为100的数组值都初始化为9

v[1] = 2;
cout << v[0];  // 直接通过下标访问

vector<int> a; // 定义的时候不指定vector的⼤小 
cout << a.size() << endl; // 这个时候size是0 
for (int i = 0; i < 10; i++) {
    a.push_back(i); // 在vector a的末尾添加⼀个元素i 
}
cout << a.size() << endl; // 此时会发现a的size变成了了10
vector<int> b(15); // 定义的时候指定vector的⼤小，默认b⾥面元素都是0
cout << b.size() << endl;

vector<int> c(20, 2); // 定义的时候指定vector的⼤小并把所有的元素赋一个指定的值 
for (int i = 0; i < c.size(); i++) {
cout << c[i] << " "; }
cout << endl;

// 使⽤用迭代器器的⽅方式访问vector
for (auto it = c.begin(); it != c.end(); it++) {  // c.begin()指向容器第一个元素, c.end()指向容器最后一个元素的后一个位置
    cout << *it << " ";  // 访问元素的值要对it指针取值，所以加*号
}

```

### 集合set
set是一个集合，里面元素是各不相同的，set会按元素进行从小到大排序
```c++
#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> s;
    s.insert(1); // 向集合里插入元素
    for(int i = 0; i<5; i++){
        s.insert(i);
    }
    cout << *(s.begin()) << endl; // 输出集合s的第一个元素
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    // s.end()表示s的最后一个元素的下一个元素所在位置
    cout << endl << (s.find(2) != s.end()) << endl; // 查找集合s中的值，如果结果等于s.end()表示未找到,返回0
    cout << (s.find(10) != s.end()) << endl;        // s.find(10) != s.end() 表示能找到10这个元素,返回1
    s.erase(1); // set删除集合中的一个元素
    cout << (s.find(1) != s.end()) << endl; 

}
```

### 映射map
map是键值对，map会自动将所有的键值对按键值从小到大排序
```c++
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    map<string, int> mp;  // 定义⼀个空的map m，键是string类型的，值是int类型
    mp["hello"] = 2;  // 将key为"hello", value为2的键值对(key-value)存⼊入map中
    cout << mp["hello"] << endl;  // 访问map中key为"hello"的value
    cout << mp["world"] << endl;  // key不存在则返回0
    mp["world"] = 3;              // 将"world"键对应的值修改为3
    cout << mp["world"] << endl;
    mp[","] = 1;  // 设⽴立⼀一组键值对，键为"," 值为1
    // 用迭代器遍历，输出map中所有元素，建用it->first获取，值用it->second获取
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    // 访问map的第⼀一个元素，输出它的键和值
    cout << mp.begin()->first << " " << mp.begin()->second << endl; 
    // 访问map的最后⼀一个元素，输出它的键和值
    cout << mp.rbegin()->first << " " << mp.rbegin()->second << endl;
    // mpap元素的个数
    cout << mp.size() << endl;
    return 0;
}

```

### stack
```c++
#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> s;  // 定义一个空栈
    for(int i = 0; i <6; i++){
        s.push(i);  // 将元素i压入栈s中
    }
    cout << s.size() << endl; // 输出s的元素个数
    cout << s.top() << endl;  // 访问栈顶元素
    s.pop(); // 移除栈顶元素
}
```