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