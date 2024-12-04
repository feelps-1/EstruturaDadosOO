#include <iostream>
#include <cmath>

double n1 {sqrt(4)};
double n2 {sqrt(12.25)};
double n3 {sqrt(0.0121)};
double un {};

int main(){
    std::cout << n1 << ' ' << n2 << ' ' << n3 << '\n'; 

    std::cout << "Choose a number to calculate it square root: ";
    std::cin >> un;

    std::cout << un << " square root is: " << sqrt(un);

    return 0;
}
