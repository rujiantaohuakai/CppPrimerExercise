#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    Sales_data data1, data2;
    std::cin >> data1.bookNum >> data1.soldCnt >> data1.onePrice;
    std::cin >> data2.bookNum >> data2.soldCnt >> data2.onePrice;

    if(data1.bookNum == data2.bookNum){
        Sales_data sum;
        sum.bookNum = data1.bookNum;
        sum.soldCnt = data1.soldCnt + data2.soldCnt;
        sum.onePrice = (data1.soldCnt * data1.onePrice + data2.soldCnt * data2.onePrice) / sum.soldCnt;
        std::cout << sum.bookNum << " " << sum.soldCnt << " " << sum.onePrice << " " << std::endl;
    }
    else{
        std::cerr << "Data must refer to the same bookNum" << std::endl;
        return -1;
    }
}