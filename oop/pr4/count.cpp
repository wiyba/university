#include <iostream>

int main()
{
    int count;

    std::cout << "Количество чисел: ";
    std::cin >> count;

    if (count <= 0)
    {
        std::cout << "Чисел нет\n";
        return 0;
    }

    int number;

    std::cout << "Число: ";
    std::cin >> number;

    int largest = number;

    for (int i = 1; i < count; i++)
    {
        std::cout << "Число: ";
        std::cin >> number;

        if (number > largest)
        {
            largest = number;
        }
    }

    std::cout << "Наибольшее число: " << largest << "\n";
}
