#include <iostream>

int main()
{
    int v1, v2;
    std::cout << "Enter two integers: ";
    std::cin >> v1 >> v2;
    if(v1 > v2){
        int temp = v1;
        v1 = v2;
        v2 = temp;
    }

    while(v1 <= v2){
        std::cout << v1 << " ";
        v1++;
    }
}