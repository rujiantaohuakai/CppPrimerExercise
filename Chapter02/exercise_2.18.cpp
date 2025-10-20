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