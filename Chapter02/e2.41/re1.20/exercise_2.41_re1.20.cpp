#include <iostream>

struct Sales_data {
    std::string bookNum = "";
    int soldCnt = 0;
    double onePrice = 0.0;
};

int main()
{
    // re1.20
    std::cout << "re1.20" << std::endl;
    Sales_data item;
    while(std::cin >> item.bookNum >> item.soldCnt >> item.onePrice){
        std::cout << item.bookNum << " " << item.soldCnt << " " << item.onePrice << std::endl;
    }

    return 0;
}