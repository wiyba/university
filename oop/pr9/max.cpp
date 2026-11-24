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

    // выделяем память ровно под count чисел
    int *numbers = new int[count];

    // вводим числа, current - указатель на текущий элемент
    for (int *current = numbers; current < numbers + count; current++)
    {
        std::cout << "Число: ";
        std::cin >> *current;
    }

    // начальный максимум - первый элемент
    int largest = *numbers;

    // ищем максимум после ввода всех элементов
    for (int *current = numbers + 1; current < numbers + count; current++)
    {
        if (*current > largest)
        {
            largest = *current;
        }
    }

    std::cout << "Наибольшее число: " << largest << "\n";

    // освобождаем память
    delete[] numbers;
}
