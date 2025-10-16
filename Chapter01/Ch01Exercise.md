## 练习1.1

> 查阅你使用的编译器文档，确定它所使用的文件命名约定。编译并运行第2页的main程序。

解答：
使用msys64环境g++编译器，代码如下
```powershell
g++ Exercise_1.1.cpp -o Exercise_1.1.exe
./Exercise_1.1.exe
```
运行后程序直接退出

## 练习1.2

> 改写程序，让它返回-1。返回值-1通常被当作程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识。

解答：
程序改为return -1; 后仍可以运行
但输入`echo $?`（上个命令返回值）后，输出False，说明程序返回了-1
输入`echo $LASTEXITCODE`（上个命令退出码），输出-1，也说明程序返回了-1

## 练习1.3

> 编写程序，在标准输出上打印 Hello, World。

解答：
``` c++
#include <iostream>

int main()
{
	std::cout << "Hello, World" << std::endl;
	return 0;
}
```

## 练习1.4

> 我们的程序使用加法运算符+来将两个数相加。编写程序使用乘法运算符*，来打印两个数的积。

解答：
``` c++
#include <iostream>

int main()
{
    int v1, v2;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl;
    return 0;
}
```

## 练习1.5

> 我们将所有输出操作放在一条很长的语句中。重写程序，将每个运算对象的打印操作放在一条独立的语句中。

解答：
``` c++
#include <iostream>

int main()
{
    int v1, v2;
    std::cin >> v1 >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
    return 0;
}
```

## 练习1.6

> 解释下面程序片段是否合法。
```powershell
std::cout << "The sum of " << v1;
		  << " and " << v2;
		  << " is " << v1 + v2 << std::endl;
```
如果程序是合法的，它的输出是什么？如果程序不合法，原因何在？应该如何修正？

解答：
不合法，v1和v2之后不能有`;`
修正后如下：
```c++
std::cout << "The sum of " << v1
		  << " and " << v2
		  << " is " << v1 + v2 << std::endl;
```

## 练习1.7

> 编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息。

```c++
/*
*   注释在这里嵌套
*	/* 这里的嵌套是错的 */
*
*/

int main()
{
	return 0;
}
```

解答：
编译器错误信息：
```powershell
Exercise_1.7.cpp:5:2: error: expected unqualified-id before '/' token
    5 | */
      |  ^
```
/* */ 注释不能嵌套

## 练习1.8

> 指出下列哪些输出语句是合法的(如果有的话)：
```c++
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
预测编译这些语句会产生什么样的结果，实际编译这些语句来验证你的答案(编写一个小程序，每次将上述一条语句作为其主体)，改正每个编译错误。

解答：
第一、二、四个语句合法
```c++
std::cout << "/*"; //输出/*
std::cout << "*/"; //输出*/
std::cout << /* "*/" /* "/*" */;
```
第三个语句编译报错如下：
```powershell
    7 |     std::cout << /* "*/" */;
      |                        ^
Exercise_1.8.cpp:7:24: error: missing terminating " character
    7 |     std::cout << /* "*/" */;
      |                        ^~~~~
Exercise_1.8.cpp: In function 'int main()':
Exercise_1.8.cpp:9:5: error: expected primary-expression before 'return'
    9 |     return 0;
      |     ^~~~~~
```
原因：缺少`"`，`/* "*/`有效，后面只剩下`" */;`
改正：最后添加`"`
```c++
std::cout << /* "*/" */"; //输出 */
```

## 练习1.9

> 编写程序，使用while循环将50到100的整数相加。

解答：
```c++
#include <iostream>

int main()
{
    int sum = 0, num = 50;
    while(num <= 100){
        sum += num;
        num++;
    }
    std::cout << "The sum of the numbers from 50 to 100 is "
              << sum << std::endl;
    return 0;
}
```

## 练习1.10

> 除了++运算符将运算对象的值增加1之外，还有一个递减运算符（--）实现将值减少1。编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。

解答：
```c++
#include <iostream>

int main()
{
    int i = 10;
    while(i >= 0){
        std::cout << i << " ";
        i--;
    }
    return 0;
}
```

## 练习1.11

> 编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。

解答：
```c++
#include <iostream>

int main()
{
    int v1, v2;
    std::cout << "Enter two integers: ";
    std::cin >> v1 >> v2;
    if(v1 > v2){
        int temp = v1;
        v1 = v2;
        v2 = temp;
    }

    while(v1 <= v2){
        std::cout << v1 << " ";
        v1++;
    }
}
```

## 练习1.12

> 下面的for循环完成了什么功能？sum的终值是多少？
```
int sum = 0;
for (int i = -100; i <= 100; ++i)
	sum += i;
```

解答：
功能：求-100到100之间整数的和，sum最终为0


## 练习1.13

> 使用for循环重做1.4.1节中的所有练习（第11页）。

解答：
```c++
#include <iostream>

int main()
{
    // 1.9
    int sum = 0;
    for(int i = 50; i <= 100; i++){
        sum += i;
    }
    std::cout << "The sum of the numbers from 50 to 100 is " << sum << std::endl;

    // 1.10
    for(int i = 10; i >= 0; i--){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // 1.11
    int v1, v2;
    std::cout << "Enter two integers: ";
    std::cin >> v1 >> v2;
    if(v1 > v2){
        int temp = v1;
        v1 = v2;
        v2 = temp;
    }

    for(int i = v1; i <= v2; i++){
        std::cout << i << " ";
    }
}
```

## 练习1.14

> 对比for循环和while循环，两种形式的优缺点各是什么？

解答：
for循环可以用于循环次数已知的情况，简洁易读。
while循环可以用于循环次数未知的情况，更加灵活。

## 练习1.15

> 编写程序，包含第14页“再探编译”中讨论的常见错误。熟悉编译器生成的错误信息。

解答：

语法错误（syntax error）：
```c++
#include <iostream>
// main的参数列表漏掉了
int main(
{
    // endl之后使用了冒号
    std::cout << "Read each file." << std::endl:
    // 字符串两侧没有引号
    std::cout << Update master. << std::endl;
    // 漏掉了字符串左侧的 <<
    std::cout << "Write new master." std::endl;
    // return 0后面缺少分号
    return 0
}
```

以上代码报错如下:
```powershell
Exercise_1.15.cpp:3:5: error: cannot declare '::main' to be a global variable
    3 | int main(
      |     ^~~~
Exercise_1.15.cpp:6:48: error: found ':' in nested-name-specifier, expected '::'
    6 |     std::cout << "Read each file." << std::endl:
      |                                                ^
      |                                                ::
Exercise_1.15.cpp:6:44: error: 'std::endl' is not a class, namespace, or enumeration
    6 |     std::cout << "Read each file." << std::endl:
      |                                            ^~~~
Exercise_1.15.cpp:8:18: error: 'Update' was not declared in this scope
    8 |     std::cout << Update master. << std::endl;
      |                  ^~~~~~
Exercise_1.15.cpp:8:25: error: expected '}' before 'master'
    8 |     std::cout << Update master. << std::endl;
      |                         ^~~~~~
Exercise_1.15.cpp:4:1: note: to match this '{'
    4 | {
      | ^
Exercise_1.15.cpp:8:25: note: probably missing a comma or an operator before
    8 |     std::cout << Update master. << std::endl;
      |                         ^~~~~~
Exercise_1.15.cpp:13:2: error: expected ')' at end of input
   13 | }
      |  ^
      |  )
Exercise_1.15.cpp:3:9: note: to match this '('
    3 | int main(
      |
```

类型错误（type error）：
```c++
#include <iostream>

int main()
{
    int a = "hello";
    return 0;
}
```

以上代码报错如下：
```powershell
Exercise_1.15.cpp: In function 'int main()':
Exercise_1.15.cpp:5:13: error: invalid conversion from 'const char*' to 'int' [-fpermissive]
    5 |     int a = "hello";
      |             ^~~~~~~
      |             |
      |             const char*
```

声明错误（declaration error）：
```c++
#include <iostream>

int main()
{
    int v1 = 0, v2 = 0;
    std::cin >> v >> v2; // 使用了未定义的变量v
    // 应该使用std::cout
    cout << v1 + v2 << std::endl;
    return 0;
}
```

以上代码报错如下：
```powershell
Exercise_1.15.cpp: In function 'int main()':
Exercise_1.15.cpp:6:17: error: 'v' was not declared in this scope; did you mean 'v2'?
    6 |     std::cin >> v >> v2; // 使用了未定义的变量v
      |                 ^
      |                 v2
Exercise_1.15.cpp:8:5: error: 'cout' was not declared in this scope; did you mean 'std::cout'?
    8 |     cout << v1 + v2 << std::endl;
      |     ^~~~
      |     std::cout
In file included from Exercise_1.15.cpp:1:
C:/msys64/ucrt64/include/c++/15.1.0/iostream:65:18: note: 'std::cout' declared here
   65 |   extern ostream cout;          ///< Linked to standard output
      |
```

好习惯：
按照报告顺序来逐个修正错误，以为单个错误通常具有传递效应。
每修正一个或者一小部分明显错误后就立即重新编译代码。

## 练习1.16

> 编写程序，从cin读取一组数，输出其和。

```c++
#include <iostream>

int main()
{
    int sum = 0 , num = 0;
    std::cout << "Enter a series of integers, each followed by a space " 
              << "and enter Ctrl+Z press Enter to finish: " << std::endl;
    while(std::cin >> num){
        sum += num;
    }
    std::cout << sum << std::endl;
    return 0;
}
```

## 练习1.17

> 如果输入的所有值都是相等的，本节的程序会输出什么？如果没有重复值，输出又会是怎样的？



## 练习1.18

> 编译并运行本节的程序，给它输入全都相等的值。再次运行程序，输入没有重复的值。

```c++

```

## 练习1.19

> 修改你为1.4.1节练习1.11（第11页）所编写的程序（打印一个范围内的数），使其能处理用户输入的第一个数比第二个数小的情况。

```c++

```


## 练习1.20

> 在网站http://www.informit.com/title/032174113 上，第1章的代码目录包含了头文件 Sales_item.h。将它拷贝到你自己的工作目录中。用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。

```c++

```

## 练习1.21

> 编写程序，读取两个 ISBN 相同的 Sales_item 对象，输出他们的和。

```c++

```

## 练习1.22

> 编写程序，读取多个具有相同 ISBN 的销售记录，输出所有记录的和。

```c++

```

## 练习1.23

> 编写程序，读取多条销售记录，并统计每个 ISBN（每本书）有几条销售记录。

```c++

```

## 练习1.24

> 输入表示多个 ISBN 的多条销售记录来测试上一个程序，每个 ISBN 的记录应该聚在一起。


```c++

```

## 练习1.25

> 借助网站上的Sales_item.h头文件，编译并运行本节给出的书店程序。


```c++

```