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