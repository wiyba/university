#include <iostream>

// функция, возвращает максимум из двух чисел через return
int maximum(int first, int second)
{
    if (first > second)
    {
        return first;
    }

    return second;
}

int main()
{
    int first;
    int second;

    // вводим числа в main
    std::cout << "Первое число: ";
    std::cin >> first;
    std::cout << "Второе число: ";
    std::cin >> second;

    // вызываем функцию и выводим результат
    std::cout << "Наибольшее число: " << maximum(first, second) << "\n";
}
