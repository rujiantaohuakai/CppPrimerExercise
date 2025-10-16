#include <iostream>

int main()
{
    int sum = 0, num = 50;
    while(num <= 100){
        sum += num;
        num++;
    }
    std::cout << "The sum of the numbers from 50 to 100 is "
              << sum << std::endl;
    return 0;
}