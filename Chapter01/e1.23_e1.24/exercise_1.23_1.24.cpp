#include <iostream>
#include "Sales_item.h"

int main()
{
    int cnt = 0;
    Sales_item item_sum, current_item, item;
    std::cin >> current_item;
    item_sum = current_item;
    cnt = 1;
    while(std::cin >> item){
        if(current_item.isbn() == item.isbn()){
            cnt++;
            item_sum += item;
        }
        else{
            std::cout << item_sum << " count = " << cnt << std::endl;
            current_item = item;
            item_sum = item;
            cnt = 1;
        }
    }
    std::cout << item_sum << " count = " << cnt << std::endl;

    return 0;
}