
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
    return 0;
}
```

### queue
```c++
#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> q;  // 定义一个空队列q
    for(int i = 0; i <6; i++){
        q.push(i);  // 将元素i压入队列q中
    }
    cout << q.size() << endl; // 输出s的元素个数
    cout << q.front() << " " << q.back() << endl; // 访问队列列的队⾸首元素和队尾元素
    q.pop(); // 移除队列的队首元素
    return 0;
}
```

### unordered_map和unorder_set的使用
unordered_map 在头文件 #include <unordered_map> 中，unordered_set 在头文件 #include <unordered_set> 中，它们的用法和map、set一样，区别是不会按key排序。能缩短代码运行时间 ，提高代码效率。


### sort函数
sort函数在头文件#include <algorithm>里面，主要是对一个数组（int arr[]或 vector数组都行）进行排序。
对于vector容器，v.begin() v.end()表示头尾，而int arr[]用arr表示数组的首地址，arr+n表示尾部。
sort默认是从小到大排序的，也可以指定第三个参数cmp函数，自己定义排序规则。sort函数的cmp只能是小于、大于
比如return a < b; 或 return b < a; 而不能是<= 或者 >=, 以免造成程序越界发生段错误。
```c++
#include <iostream>
using namespace std;
struct stu { // 定义⼀一个结构体stu，number表示学号，score表示分数
    int number;
    int score; 
}
bool cmp(stu a, stu b){
    if(a.score != b.score)
        return a.score > b.score;
    else
        return a.number < b.number;
}
bool cmp(stu a, stu b){
    return a.score != b.score ? a.score > b.score : a.number < b.number;
}

```
```c++
    bool cmp(int a, int b){ 
        return a>b;   // 从大到小排序
    } 
    int main(){
        vector<int> v(10);
        for(int i =0; i<10; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end()); // 没有传入参数cmp，所以按照默认从小到大排序
        int arr[10];
        for(int i = 0; i <10; i++){
            cin >> arr[i];
        }
        sort(arr, arr+10, cmp);  // cmp设置了从大到小，因此arr从大到小排序
        return 0;
    }
```

### cctype头文件
#include <cctype> 本质上来源于C语言标准函数库中的头文件 #include <ctype.h> ，并不属于C++新特性的范畴。常用的函数有以下几个。
isalpha 字⺟母(包括⼤写、⼩写) 
islower (小写字母)
isupper (⼤写字母)
isalnum (字⺟大写小写+数字) 
isblank (space和 \t )
isspace ( space 、 \t 、 \r 、 \n )
tolower 将字符转换为小写
toupper 将字符转换为大写
```c++
#include <iostream>
#include <cctype>
using namespace std;
// 判断一个字符是否是字母的普通方式
char c;
cin >> c;
if(c >= 'A' && c <= 'Z' || c>'a' && c<'z'){
    cout << 'c is alpha';
}
// 使用cctype里提供的isalpha函数
if(isalpha(c)){
    cout << 'c is alpha';
}
char s = 'A';
char t = tolower(s);  // 等同于 t = t + 32;
char u = toupper(t);
```

### c++11
C++11是2011年官方为C++语⾔带来的新语法新标准，C++11为C++语言带来了很多好⽤用的新特性，⽐如 auto 、 to_string() 函数、 stoi 、 stof 、unordered_map 、 unordered_set 之类
```c++
// auto 可以让编译器根据初始值类型直接推断出变量类型
auto x = 100;
auto y = 1.5;
for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    cout << *it << " ";

for(auto it = s.begin(); it != s.end(); it++){
    cout << *it << " ";
}
```

### 基于范围的for循环
C++11中添加了基于范围的for循环，在遍历数组中的每一个元素时使用会比较方便
```c++
int arr[4] = {0,1,2,3};
for(int i : arr){
    cout << i << endl; // 输出数组中每一个元素的值，每个元素占据一行
}
```
使用 int i 的⽅式定义时，该语句只能⽤来输出数组中元素的值，⽽而不能修改数组中的元素，如果想要修改， 必须使⽤ int &i 这种定义引用变量的⽅方式.
```c++
int arr[4] = {0,1,2,3};
for(int &i : arr){
    i = i * 2;
    cout << i << endl; // 输出数组中每一个元素的值，每个元素占据一行
}

// v是一个int类型的vector容器
for(auto i : v)
    cout << i << " ";
// 等价于
for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
```

### to_string
to_string的头文件是`#include <string>` ,可以把int、float、double类型的变量转换为string类型。
```c++
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s1 = to_string(123);  // 把123这个数字转成字符串
    cout << s1 << endl;
    string s2 = to_string(4.5); // 将4.5这个数字转成字符串
    cout << s2 << endl;
    cout << s1+s2 << endl;  // 将s1和s2两个字符串拼接起来并输出
    printf("%s\n", (s1+s2).c_str()); // 如果想用printf输出string，得加一个.c_str()
    return 0;
```

### c++11中的stoi stod
c++11中的`stoi`和`stod`可以将字符串`string`转化为对应的`int`型和`double`型变量。
在字符串处理的很多问题中很有帮助。
stoi如果遇到的是非法输入（比如stoi("123.4")不是一个int型变量）,会自动截取最前面的数字，直到遇到不是数字为止，浮点型会截取前面的整数部分。
如果最前面不是数字，会运行发生错误。

stod如果是非法输入：
1. 会自动截取最前面的浮点数，直到遇到不满足浮点数为止
2. 如果最前面不是数字或者小数点，会运行时发生错误
3. 如果最前面是小数点，会自动转化后在前面补0
```c++
#include <iostream>
#include <string>
using namespace std;
int main(){
    string str = "123";
    int a = stoi(str);
    cout << a;
    str = "123.45";
    double b = stod(str);
    cout << b;
    return 0;
}
```
`stof` string to float
`stold` string to long double
`stol` string to long
`stoll` string to long long
`stoull` string to unsigned long long

### C++位运算bitset
bitset用来处理二进制位，头文件是`#include <bitset>`
bitset相当于一个数组，但是它是从二进制的低位到高位分别为b[0]、b[1]......的
所以按照b[i]方式逐位输出和直接输出b结果相反的
```c++
#include <iostream>
#include <bitset>
using namespace std;
int main(){
    bitset<5> b("11"); // 5表示5个二进位
    // 初始化方式
    // bitset<5> b; 都为0
    // bitset<5> b(u); u为unsigned int,如果u = 1，则输出b的结果为00001
    // bitset<8> b(s); s为字符串，如”1101“，则输出b的结果为00001101，在前⾯补0
    // bitset<5> b(s, pos, n); 从字符串的s[pos]开始，n位长度

    cout << b << endl;  // 如果bitset<5> b("11"); 则此处输出00011(即正常二进制顺序)
    for(int i = 0; i < 5; i++){
        cout << b[i]; // 如果bitset<5> b("11");则此处输出11000,正常二进制顺序的倒序
    }

```