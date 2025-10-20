#include <iostream>

struct Sales_data {
    std::string bookNum = "";
    int soldCnt = 0;
    double onePrice = 0.0;
};

int main()
{
    // re1.25
    Sales_data total;
    if(std::cin >> total.bookNum >> total.soldCnt >> total.onePrice){
        int total_sold = total.soldCnt; // 记录总销量
        double total_revenue = total.onePrice * total.soldCnt; // 记录总销售额

        Sales_data trans; // 用于保存下一条交易记录
        while(std::cin >> trans.bookNum >> trans.soldCnt >> trans.onePrice){
            if(trans.bookNum == total.bookNum){
                total_sold += trans.soldCnt;
                total_revenue += trans.onePrice * trans.soldCnt;
            }
            else{
                std::cout << total.bookNum << " " << total_sold << " "
                          << total_revenue << " " << total_revenue / total_sold << std::endl;
                
                total.bookNum = trans.bookNum;
                total.soldCnt = trans.soldCnt;
                total.onePrice = trans.onePrice;

                total_sold = total.soldCnt;
                total_revenue = total.onePrice * total.soldCnt;
            }
        }
        std::cout << total.bookNum << " " << total_sold << " "
                          << total_revenue << " " << total_revenue / total_sold << std::endl;
    }
    else{
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}