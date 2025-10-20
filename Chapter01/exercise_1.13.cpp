#include <iostream>

int main()
{
    // 1.9
    int sum = 0;
    for(int i = 50; i <= 100; i++){
        sum += i;
    }
    std::cout << "The sum of the numbers from 50 to 100 is " << sum << std::endl;

    // 1.10
    for(int i = 10; i >= 0; i--){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // 1.11
    int v1, v2;
    std::cout << "Enter two integers: ";
    std::cin >> v1 >> v2;
    if(v1 > v2){
        int temp = v1;
        v1 = v2;
        v2 = temp;
    }

    for(int i = v1; i <= v2; i++){
        std::cout << i << " ";
    }
}