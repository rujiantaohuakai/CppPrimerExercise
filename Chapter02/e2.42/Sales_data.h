#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {
    std::string bookNum = "";
    int soldCnt = 0;
    double onePrice = 0.0;
};

#endif // SALES_DATA_H