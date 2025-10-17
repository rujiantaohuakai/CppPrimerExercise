#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item_sum;
    // 注意要把第一个输入item_sum，不然item_sum没有书号
    std::cin >> item_sum;
    for(Sales_item item; std::cin >> item; ){
        item_sum += item;
    }
    std::cout << "Sum of all items: " << item_sum << std::endl;
    return 0;
}