#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2, sum;
    std::cin >> item1 >> item2;
    sum = item1 + item2;
    std::cout << sum << std::endl;
    return 0;
}