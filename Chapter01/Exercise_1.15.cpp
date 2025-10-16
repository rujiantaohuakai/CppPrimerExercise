#include <iostream>

int main()
{
    int v1 = 0, v2 = 0;
    std::cin >> v >> v2; // 使用了未定义的变量v
    // 应该使用std::cout
    cout << v1 + v2 << std::endl;
    return 0;
}