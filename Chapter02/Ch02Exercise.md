# 第二章 变量和基本类型 

换用Ubuntu24环境进行练习

## 练习2.1
类型 int、long、long long 和 short 的区别是什么？无符号类型和带符号类型的区别是什么？float 和 double的区别是什么？

解答：
- int：整数类型，通常为32位，取值范围为-2147483648到2147483647。
- long：长整数类型，通常为64位，取值范围为-9223372036854775808到9223372036854775807。
- long long：长长整数类型，通常为64位，取值范围为-9223372036854775808到9223372036854775807。
- short：短整数类型，通常为16位，取值范围为-32768到32767。

- 无符号类型表示大于等于0的数，带符号类型表示负数、0和正数。

- float：单精度浮点类型，通常为32位，精度为6-7位小数，取值范围为3.4e-38到3.4e+38。
- double：双精度浮点类型，通常为64位，精度为15-16位小数，取值范围为1.7e-308到1.7e+308。

## 练习2.2
计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

解答：

全部选用`double`。利率、本金和付款都需要进行浮点计算。

## 练习2.3
读程序写结果。
```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

解答:
```
32
4294967264 原因：(-32 + 2^32) % 2^32 = 4294967264
32
-32
0
0
```

## 练习2.4
编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。

解答：
```cpp
#include <iostream>

int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
    return 0;
}
```
运行后与之前的回答一致。

## 练习2.5
指出下述字面值的数据类型并说明每一组内几种字面值的区别：
```
(a) 'a', L'a', "a", L"a"
(b) 10, 10u, 10L, 10uL, 012, 0xC
(c) 3.14, 3.14f, 3.14L
(d) 10, 10u, 10., 10e-2
```

解答：
(a):
```
'a' char型字面值
L'a' wchar_t型宽字符字面值
"a" 字符串型字面值
L"a" 宽字符串型字面值
```

(b)
```
10 带符号十进制整型字面值
10u 无符号十进制整型字面值
10L 带符号十进制long整型字面值
10uL 无符号十进制long整型字面值
012 八进制整型字面值
0xC 十六进制整型字面值
```

(c)
```
3.14 double型浮点字面值
3.14f float型浮点字面值
3.14L long double型浮点字面值
```

(d)
```
10 带符号十进制整型字面值
10u 无符号十进制整型字面值
10. double型浮点字面值
10e-2 double型浮点字面值
```

## 练习2.6
下面两组定义是否有区别，如果有，请叙述之：
```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```

解答：
第一行是十进制整形，第二行是八进制整形，但month变量有误，八进制不能直接写9。

## 练习2.7
下述字面值表示何种含义？它们各自的数据类型是什么？
```cpp
(a) "Who goes with F\145rgus?\012"
(b) 3.14e1L
(c) 1024f
(d) 3.14L
```

解答：
(a) Who goes with Fergus?(换行) 字符串型字面值
(b) long double类型
(c) 无效，因为后缀f只能用于浮点字面量，而1024是整型，编译报错如下：
```bash
test.cpp: In function ‘int main()’:
test.cpp:5:18: error: unable to find numeric literal operator ‘operator""f’
    5 |     std::cout << 1024f << std::endl;
      |                  ^~~~~
```
(d) long double类型。



## 练习2.8
请利用转义序列编写一段程序，要求先输出 2M，然后转到新一行。修改程序使其先输出 2，然后输出制表符，再输出 M，最后转到新一行。

解答：
```cpp
#include <iostream>

int main()
{
    // 16进制转义字符
    std::cout << "\x32\x4D\n";
    std::cout << "\x32\t\x4D\n";

    // 8进制转义字符
    std::cout << "\62\115\n";
    std::cout << "\62\t\115\n";
    return 0;
}
```

## 练习2.9
解释下列定义的含义，对于非法的定义，请说明错在何处并将其改正。

- (a) std::cin >> int input_value;
- (b) int i = { 3.14 };
- (c) double salary = wage = 9999.99;
- (d) int I = 3.14;

解答：
解： 
编译报错如下：
```bash
exercise_2.9.cpp: In function ‘int main()’:
exercise_2.9.cpp:5:17: error: expected primary-expression before ‘int’
    5 |     std::cin >> int input_value;
      |                 ^~~
exercise_2.9.cpp:6:15: error: narrowing conversion of ‘3.1400000000000001e+0’ from ‘double’ to ‘int’ [-Wnarrowing]
    6 |     int i = { 3.14 };
      |               ^~~~
exercise_2.9.cpp:7:21: error: ‘wage’ was not declared in this scope
    7 |     double salary = wage = 9999.99;
      |
```

改正：
(a): 应该先定义input_value再使用。改：
```cpp
int input_value = 0;
std::cin >> input_value;
```

(b): 用列表初始化内置类型的变量时，如果存在丢失信息的风险，则编译器将报错。改：
```cpp
double i = { 3.14 };
```

(c): 在这里`wage`是未定义的，应该在此之前将其定义。改：
```cpp
double wage;
double salary = wage = 9999.99;
```

(d): 没有报错，但只会保留整数部分。改：
```cpp
double i = 3.14;
```

## 练习2.10
下列变量的初值分别是什么？
```cpp
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
```
解答：
```cpp
#include <iostream>

std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
    std::cout << "global_str: " << global_str << std::endl;
    std::cout << "global_int: " << global_int << std::endl;
    std::cout << "local_int: " << local_int << std::endl;
    std::cout << "local_str: " << local_str << std::endl;
    return 0;
}
```
输出：
```
global_str: 
global_int: 0
local_int: 0
local_str: 
```
`strig global_str`为`空串`
`global_int`为`0`
`local_int`为未定义的变量
`local_str`为`空串`
程序运行后虽然local_int有输出值，但是是不确定的值

## 练习2.11
指出下面的语句是声明还是定义：

- (a) extern int ix = 1024;
- (b) int iy;
- (c) extern int iz;

解答：
- (a): 定义，任何包含了显示初始化的声明即成为定义。给ix赋初始值抵消了extern的作用
- (b): 定义
- (c): 声明，extern用于声明一个变量，但并不定义它。

## 练习2.12
请指出下面的名字中哪些是非法的？

- (a) int double = 3.14;
- (b) int _;
- (c) int catch-22;
- (d) int 1_or_2 = 1;
- (e) double Double = 3.14;

解答：
(a)：不合法，不能用关键字double作为变量名
(b)：合法，可以用下划线作为变量名，但不推荐这样写
(c)：不合法，关键字catch不能用在变量名中
(d)：不合法，不能用数字开头
(e)：合法，但不推荐这样写

## 练习2.13
下面程序中`j`的值是多少？

```cpp
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

解答：
`j`的值是100，局部变量`i`覆盖了全局变量`i`。

## 练习2.14
下面的程序合法吗？如果合法，它将输出什么？
```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
std::cout << i << " " << sum << std::endl;
```

合法，输出`100 45`。

## 练习2.15
下面的哪个定义是不合法的？为什么？

- (a) int ival = 1.01;
- (b) int &rval1 = 1.01;
- (c) int &rval2 = ival;
- (d) int &rval3;

解答：
(b): 引用类型的初始值必须是一个对象。
(d): 引用必须初始化

## 练习2.16
考察下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了哪些操作？

```cpp
int i = 0, &r1 = i; 
double d = 0, &r2 = d;
```
- (a) r2 = 3.14159;
- (b) r2 = r1;
- (c) i = r2;
- (d) r1 = d;

解答：
- (a): 合法。相当于给 d 赋值为 3.14159
- (b): 合法。相当于给 d 赋值为 i 的值 0
- (c): 合法。相当于给 i 赋值为 d 的整数部分
- (d): 合法。相当于给 i 赋值为 d 的整数部分

## 练习2.17
执行下面的代码段将输出什么结果？
```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

解答：
输出：`10 10`

## 练习2.18
编写代码分别改变指针的值以及指针所指对象的值。

解答：
```cpp
#include <iostream>

int main()
{
    int val = 100;
    int *p = nullptr;
    // 更改指针的值
    std::cout << "Before: " << p << std::endl;
    p = &val;
    std::cout << "After: " << p << std::endl;
    // 更改指针所指对象的值
    std::cout << "Before: " << *p << std::endl;
    *p = 200;
    std::cout << "After: " << *p << std::endl;
    return 0;
}
```

## 练习2.19
说明指针和引用的主要区别

解答：
指针是一个对象，存储另一个对象的地址，可以修改指针指向的地址
引用相当于对象的别名，引用只能访问最初绑定的对象，不能改变引用绑定的对象

## 练习2.20
请叙述下面这段代码的作用。

```cpp
int i = 42;
int *p1 = &i; 
*p1 = *p1 * *p1;
```

解答：
定义int型变量i
定义int型指针p1并让它指向i的地址
为*p1也就是i赋值为*p1 * *p1，即i=i*i

## 练习2.21
请解释下述定义。在这些定义中有非法的吗？如果有，为什么？

`int i = 0;`
- (a) double* dp = &i;
- (b) int *ip = i;
- (c) int *p = &i;

解答：
(a) 非法，指针的类型和它所指向对象的类型必须匹配
(b) 非法，不能将整型值赋给指针，要用`&i`

## 练习2.22
假设 p 是一个 int 型指针，请说明下述代码的含义。

```cpp
if (p) // ...
if (*p) // ...
```

解答：
- 如果p不为空，则执行...
- 如果*p不为0，则执行...

## 练习2.23
给定指针 p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。

解答：
不能，因为指针不一定合法。

## 练习2.24
在下面这段代码中为什么 p 合法而 lp 非法？
```cpp
int i = 42;
void *p = &i;
long *lp = &i;
```

解答：
p是void*类型的指针，可以指向任意类型的对象，lp是long*类型的指针，它指向的对象必须是long型的。

## 练习2.25
说明下列变量的类型和值。
```cpp
(a) int* ip, i, &r = i;
(b) int i, *ip = 0;
(c) int* ip, ip2;
```

解答：
- (a) ip是int型指针，i是int型变量，r是int型引用
- (b) i是int型指针，ip是int型空指针
- (c) ip是int型指针，ip2是int型变量 

## 练习2.26
下面哪些语句是合法的？如果不合法，请说明为什么？
```cpp
(a) const int buf;
(b) int cnt = 0;
(c) const int sz = cnt;
(d) ++cnt; ++sz;
```

解答：
- (a): 不合法，const对象必须初始化
- (b): 合法
- (c): 合法
- (d): 不合法，const对象不能被修改

## 练习2.27
下面的哪些初始化是合法的？请说明原因。
```cpp
(a) int i = -1, &r = 0;
(b) int *const p2 = &i2;
(c) const int i = -1, &r = 0;
(d) const int *const p3 = &i2;
(e) const int *p1 = &i2;
(f) const int &const r2;
(g) const int i2 = i, &r = i;
```

解答：

- (a): 不合法，引用的初始化必须是一个对象
- (b): 合法，p2是常量指针，可以指向常量或者非常量
- (c): 合法，在初始化常量引用时可以用任意表达式作为初始值，比如非常量的对象、字面值、一般表达式
- (d): 合法，p3是指向常量对象的常量指针
- (e): 合法，p1是指向常量对象的指针，不能用于修改指针对象的值，但是可以指向常量或者非常量对象
- (f): 不合法，引用没有顶层const
- (g): 合法，i2是常量对象，r是常量引用，可以指向常量或者非常量对象

一些理解：
```cpp
// 常量引用（对常量的引用），理解：常量引用是对const的引用，不能修改它所绑定的对象，
// 常量必须使用对常量的引用，但常量引用在初始化时时可以用任意表达式作为初始值，比如非常量的对象、字面值、一般表达式
const int i = 1;
const int &r1 = i; // r1是对常量的引用
const int &r2 = 42; // 正确
const int &r3 = r1 * 2; // 正确

// 指向常量的指针，理解：指向常量的指针仅要求不能通过该指针改变对象的值，
// 但没规定那个对象的值不能通过其他途径改变
const int i = 1;
int j = 2；
const int *p = &i; // p是指向常量的指针，不能改变所指对象的值
p = &j; // 指向常量的指针可以指向非常量对象，但不能改变对象的值

// const指针/常量指针，理解：必须初始化，而且初始化后指针的值不能再改变，
// 可以指向常量也可以指向非常量对象，能否修改指向对象的值取决于对象的类型。
const int i = 1;
int j = 2;
int *const p = &i; // p是常量指针，指向常量对象
p = &j; // p是常量指针，指向int型对象，可以修改对象的值
```

## 练习2.28
说明下面的这些定义是什么意思，挑出其中不合法的。
```cpp
(a) int i, *const cp;
(b) int *p1, *const p2;
(c) const int ic, &r = ic;
(d) const int *const p3;
(e) const int *p;
```

解答：
- (a): 不合法，常量指针cp必须初始化
- (b): 不合法，常量指针p2必须初始化
- (c): 不合法，常量ic必须初始化
- (d): 不合法，指向常量的常量指针p3必须初始化
- (e): 合法，指向const int的指针

## 练习2.29
假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因。
```cpp
(a) i = ic;
(b) p1 = p3;
(c) p1 = &ic;
(d) p3 = &ic;
(e) p2 = p1;
(f) ic = *p3;
```

解答：（假设上一个练习中的变量都正确定义了，如下）
```cpp
int i, *const cp = &1;
int *p1 = &i, *const p2 = &i;
const int ic = 10, &r = ic;
const int *const p3 = &ic;
const int *p;
```

- (a): 合法，i可以被赋值为常量ic
- (b): 不合法，指针p1不能指向常量指针p3
- (c): 不合法，指针p1不能指向常量ic
- (d): 合法，p3可以指向常量ic
- (e): 不合法，常量指针p2初始化后不能再指向其他对象
- (f): 不合法，ic是常量，不能修改它的值

## 练习2.30
对于下面的这些语句，请说明对象被声明成了顶层const还是底层const？

```cpp
const int v2 = 0; int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```

解答：顶层const表示自身是常量，底层const表示所指的对象是常量。
v2是顶层const
p2是底层const
p3既是底层const又是顶层const
r2是底层const

## 练习2.31
假设已有上一个练习中所做的那些声明，则下面的哪些语句是合法的？请说明顶层const和底层const在每个例子中有何体现。
```cpp
(a) r1 = v2;
(b) p1 = p2;
(c) p2 = p1;
(d) p1 = p3;
(e) p2 = p3;
```

解答：
- (a): 合法，相当于给v1赋值为v2
- (b): 不合法，p2是const int *，p1是int *，如果p1指向p2则通过p1可以修改p2指向的对象的值，但p2指向的对象是const int，不能修改
- (c): 合法，p2可以指向p1，但不能修改p1指向的对象的值。可以把普通指针转换成“指向常量的指针”
- (d): 不合法，p3有底层const，不能修改指向的对象的值，所以p1不能指向p3
- (e): 合法，p2和p3都是const int *，p3还有顶层const，但不影响拷贝，只是p3自身不能被修改


## 练习2.32
下面的代码是否合法？如果非法，请设法将其修改正确。
```cpp
int null = 0, *p = null;
```

解答：
非法，不能将int型变量null赋值给指针p，要将p初始化为空指针正确应该是：
```cpp
int null = 0, *p = 0; // 或 p = nullptr;
```

## 练习2.33
利用本节定义的变量，判断下列语句的运行结果。
```cpp
a = 42;
b = 42;
c = 42;
d = 42;
e = 42;
g = 42;
```

解答：
- a：合法，a是int型，所以42可以赋值给它
- b：合法，b是int型，所以42可以赋值给它
- c：合法，c是int型，所以42可以赋值给它
- d：非法，d是int型指针，42不能赋值给它，因为指针不能直接赋值
- e：非法，e是const int型指针，所以42不能赋值给它，因为const对象不能被修改
- g：非法，g是const int型引用，所以42不能赋值给它，因为const对象不能被修改

## 练习2.34
基于上一个练习中的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的推断正确吗？如果不对，请反复研读本节的示例直到你明白错在何处为止。

解答：
```cpp
#include <iostream>

int main()
{
    int i = 0, &r = i;
	auto a = r;   // a是一个整数（r是i的别名，而i是以一个整数）

	const int ci = i, &cr = ci;
	auto b = ci; // b是一个整数（ci的顶层const特性被忽略掉了）
	auto c = cr; // c是一个整数（cr是ci的别名，ci本身是一个顶层const）
	auto d = &i; // d是一个整型指针（整数的地址就是指向整数的指针）
	auto e = &ci; // e是一个指向整数常量的指针（对常量对象去地址是一种底层const）

	const auto f = ci; // ci的推演类型是int，f是const int
	auto &g = ci; // g是一个整型常量引用，绑定到ci

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << std::endl;

	a = 42;
	b = 42;
	c = 42;
	// d = 42;
	// e = 42;
	// g = 42;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	// std::cout << "d = " << d << std::endl;
	// std::cout << "e = " << e << std::endl;
	// std::cout << "g = " << g << std::endl;

}
```
输出：
```
a = 0
b = 0
c = 0
d = 0x7ffe63754dd8
e = 0x7ffe63754ddc
g = 0

a = 42
b = 42
c = 42
```
不注释d e g，编译时有如下报错：
```bash
exercise_2.34.cpp: In function ‘int main()’:
exercise_2.34.cpp:28:13: error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
   28 |         d = 42;
      |             ^~
      |             |
      |             int
exercise_2.34.cpp:29:13: error: invalid conversion from ‘int’ to ‘const int*’ [-fpermissive]
   29 |         e = 42;
      |             ^~
      |             |
      |             int
exercise_2.34.cpp:30:11: error: assignment of read-only reference ‘g’
   30 |         g = 42;
      |         ~~^~~~
```

## 练习2.35
判断下列定义推断出的类型是什么，然后编写程序进行验证。

```cpp
const int i = 42;
auto j = i;
const auto &k = i;
auto *p = &i; 
const auto j2 = i, &k2 = i;
```

解答：
- i是const int型
- j是int型，顶层const特性被忽略掉了
- k是const int型的引用，绑定到i
- p是指向const int型的指针const int *，指向i
- j2是const int型
- k2是const int型的引用，绑定到i

## 练习2.36
关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。

```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```

解答：
- a：int型，结束后值为4
- b：int型，结束后值为4
- c：int型，结束后值为4
- d：int型的引用，绑定到a，结束后值为4

## 练习2.37
赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。也就是说，如果 i 是 int，则表达式 i=x 的类型是 int&。根据这一特点，请指出下面的代码中每一个变量的类型和值。

```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```

解答：
- a：int型，值为3
- b：int型，值为4
- c：int型，值为3
- d：int型的引用，绑定到a，值为3

## 练习2.38
说明由decltype 指定类型和由auto指定类型有何区别。请举一个例子，decltype指定的类型与auto指定的类型一样；再举一个例子，decltype指定的类型与auto指定的类型不一样。

解答：
decltype的结果类型与表达式形式相关，不会忽略顶层 const 或引用
而auto通过初始值来推断类型（所以auto定义的变量必须有初始值），会忽略顶层 const 和引用
```cpp
int a = 0, *p = &a, &r = a;
// 例子1：decltype指定的类型与auto指定的类型一样
decltype(a) x = a; // x的类型是int
auto y = a; // y的类型是int

// 例子2：decltype指定的类型与auto指定的类型不一样
decltype((a)) x = a; // x的类型是int& 加了一层括号，(a)是左值表达式，所以结果是引用类型
auto y = a; // y的类型是int

decltype(r) x = a; // x的类型是int&
auto y = a; // y的类型是int

decltype(p) x = p; // x的类型是int*
auto y = a; // y的类型是int

decltype(*p) x = a; // x的类型是int& 注意：*p是解引用操作，decltype(*p)的结果是引用类型
auto y = a; // y的类型是int

// 额外：
auto y = p; // y的类型是int*
auto y = *p; // y的类型是int
auto y = r; // y的类型是int
```

## 练习2.39
编译下面的程序观察其运行结果，注意，如果忘记写类定义体后面的分号会发生什么情况？记录下相关的信息，以后可能会有用。
```cpp
struct Foo { /* 此处为空  */ } // 注意：没有分号
int main()
{
    return 0;
}
```

解答：
编译后报错如下：
```bash
exercise_2.39.cpp:3:31: error: expected ‘;’ after struct definition
    3 | struct Foo { /* 此处为空  */ } // 注意：没有分号
      |                               ^
      |                               ;
```
指出了错误位置，给出了修改建议

## 练习2.40
根据自己的理解写出 Sales_data 类，最好与书中的例子有所区别。

解答：
```cpp
struct Sales_data {
    std::string bookNum = "";
    int soldCnt = 0;
    double onePrice = 0.0;
};
```

## 练习2.41
使用你自己的Sale_data类重写1.5.1节（第20页）、1.5.2节（第21页）和1.6节（第22页）的练习。眼下先把Sales_data类的定义和main函数放在一个文件里。

解答：
### re1.5.1

#### re1.20

```cpp
#include <iostream>

struct Sales_data {
    std::string bookNum = "";
    int soldCnt = 0;
    double onePrice = 0.0;
};

int main()
{
    // re1.20
    std::cout << "re1.20" << std::endl;
    Sales_data item;
    while(std::cin >> item.bookNum >> item.soldCnt >> item.onePrice){
        std::cout << item.bookNum << " " << item.soldCnt << " " << item.onePrice << std::endl;
    }

    return 0;
}
```

#### re1.21

```cpp
#include <iostream>

struct Sales_data {
    std::string bookNum = "";
    int soldCnt = 0;
    double onePrice = 0.0;
};

int main()
{
    // re1.21
    Sales_data item1;
    Sales_data item2;

    std::cin >> item1.bookNum >> item1.soldCnt >> item1.onePrice;
    std::cin >> item2.bookNum >> item2.soldCnt >> item2.onePrice;

    if(item1.bookNum == item2.bookNum){
        std::cout << item1.bookNum << " ";
        int total_sold = item1.soldCnt + item2.soldCnt;
        std::cout << total_sold << " ";
        double total_revenue = item1.onePrice * item1.soldCnt + item2.onePrice * item2.soldCnt;
        std::cout << total_revenue << " ";
        std::cout << total_revenue / total_sold << std::endl;
    }

    return 0;
}
```

#### re1.22

```cpp
#include <iostream>

struct Sales_data {
    std::string bookNum = "";
    int soldCnt = 0;
    double onePrice = 0.0;
};

int main()
{
    // re1.22
    Sales_data item, current_item; 
    std::cin >> item.bookNum >> item.soldCnt >> item.onePrice;
    int total_sold = item.soldCnt; // 记录总销量
    double total_revenue = item.onePrice * item.soldCnt; // 记录总销售额
    while(std::cin >> current_item.bookNum >> current_item.soldCnt >> current_item.onePrice){
        if(current_item.bookNum == item.bookNum){
            total_sold += current_item.soldCnt;
            total_revenue += current_item.onePrice * current_item.soldCnt;
        }
    }
    std::cout << item.bookNum << " " << total_sold << " "
              << total_revenue << " " << total_revenue / total_sold << std::endl;

    return 0;
}
```

### re1.5.2

#### re1.23 & re1.24

```cpp
#include <iostream>

struct Sales_data {
    std::string bookNum = "";
    int soldCnt = 0;
    double onePrice = 0.0;
};

int main()
{
    // re1.23 re1.24
    Sales_data item, current_item; 
    std::cin >> item.bookNum >> item.soldCnt >> item.onePrice;
    int total_sold = item.soldCnt; // 记录总销量
    double total_revenue = item.onePrice * item.soldCnt; // 记录总销售额
    int cnt = 1; // 记录当前书的数量
    while(std::cin >> current_item.bookNum >> current_item.soldCnt >> current_item.onePrice){
        if(current_item.bookNum == item.bookNum){
            cnt++;
            total_sold += current_item.soldCnt;
            total_revenue += current_item.onePrice * current_item.soldCnt;
        }
        else{
            std::cout << item.bookNum << " " << total_sold << " "
                      << total_revenue << " " << total_revenue / total_sold << " count = " << cnt << std::endl;
            
            item.bookNum = current_item.bookNum;
            item.soldCnt = current_item.soldCnt;
            item.onePrice = current_item.onePrice;

            total_sold = item.soldCnt;
            total_revenue = item.onePrice * item.soldCnt;
            cnt = 1;
        }
    }

    std::cout << item.bookNum << " " << total_sold << " "
              << total_revenue << " " << total_revenue / total_sold << " count = " << cnt << std::endl;

    return 0;
}
```

### re1.6

#### re1.25

```cpp
#include <iostream>

struct Sales_data {
    std::string bookNum = "";
    int soldCnt = 0;
    double onePrice = 0.0;
};

int main()
{
    // re1.25
    Sales_data total;
    if(std::cin >> total.bookNum >> total.soldCnt >> total.onePrice){
        int total_sold = total.soldCnt; // 记录总销量
        double total_revenue = total.onePrice * total.soldCnt; // 记录总销售额

        Sales_data trans; // 用于保存下一条交易记录
        while(std::cin >> trans.bookNum >> trans.soldCnt >> trans.onePrice){
            if(trans.bookNum == total.bookNum){
                total_sold += trans.soldCnt;
                total_revenue += trans.onePrice * trans.soldCnt;
            }
            else{
                std::cout << total.bookNum << " " << total_sold << " "
                          << total_revenue << " " << total_revenue / total_sold << std::endl;
                
                total.bookNum = trans.bookNum;
                total.soldCnt = trans.soldCnt;
                total.onePrice = trans.onePrice;

                total_sold = total.soldCnt;
                total_revenue = total.onePrice * total.soldCnt;
            }
        }
        std::cout << total.bookNum << " " << total_sold << " "
                          << total_revenue << " " << total_revenue / total_sold << std::endl;
    }
    else{
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}
```

## 练习2.42
根据你自己的理解重写一个Sales_data.h头文件，并以此为基础重做2.6.2节（第67页）的练习。

### 头文件：

```cpp
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {
    std::string bookNum = "";
    int soldCnt = 0;
    double onePrice = 0.0;
};

#endif // SALES_DATA_H
```

### 重写练习

```cpp
#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    Sales_data data1, data2;
    std::cin >> data1.bookNum >> data1.soldCnt >> data1.onePrice;
    std::cin >> data2.bookNum >> data2.soldCnt >> data2.onePrice;

    if(data1.bookNum == data2.bookNum){
        Sales_data sum;
        sum.bookNum = data1.bookNum;
        sum.soldCnt = data1.soldCnt + data2.soldCnt;
        sum.onePrice = (data1.soldCnt * data1.onePrice + data2.soldCnt * data2.onePrice) / sum.soldCnt;
        std::cout << sum.bookNum << " " << sum.soldCnt << " " << sum.onePrice << " " << std::endl;
    }
    else{
        std::cerr << "Data must refer to the same bookNum" << std::endl;
        return -1;
    }
}
```


