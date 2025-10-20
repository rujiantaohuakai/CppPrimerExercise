#include <iostream>

int main()
{
    int sum = 0 , num = 0;
    std::cout << "Enter a series of integers, each followed by a space " 
              << "and enter Ctrl+Z press Enter to finish: " << std::endl;
    while(std::cin >> num){
        sum += num;
    }
    std::cout << sum << std::endl;
    return 0;
}