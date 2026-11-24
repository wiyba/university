#include <iostream>

int main()
{
    int number;

    std::cout << "Число: ";
    std::cin >> number;

    if (number == 0)
    {
        std::cout << "Не введено ни одного числа\n";
        return 0;
    }

    int largest = number;

    while (number != 0)
    {
        if (number > largest)
        {
            largest = number;
        }

        std::cout << "Число: ";
        std::cin >> number;
    }

    std::cout << "Наибольшее число: " << largest << "\n";
}
