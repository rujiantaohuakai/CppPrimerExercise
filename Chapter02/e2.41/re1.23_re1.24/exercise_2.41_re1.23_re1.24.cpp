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