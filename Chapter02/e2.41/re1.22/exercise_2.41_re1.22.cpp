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