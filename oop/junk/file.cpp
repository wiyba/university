#include <iostream>
int main()
{
    int n = 2;
    int *u;
    u = &n;
    std::cout << "n == " << n << "\n";
    std::cout << "n address == " << &n << "\n";
    std::cout << "u == " << u << "\n";
    std::cout << "u address value == " << *u << "\n";
    *u = 10;
    std::cout << "u address value now == " << *u << "\n";
    n = 11;
    n++;
    std::cout << "u address value now 2 == " << *u << "\n";
}
