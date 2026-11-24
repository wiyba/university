#include <iostream>
#include <vector>

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

    // создаем пустой вектор
    std::vector<int> numbers;

    // вводим числа и добавляем их в конец вектора
    for (int i = 0; i < count; i++)
    {
        int number;

        std::cout << "Число: ";
        std::cin >> number;

        numbers.push_back(number);
    }

    // начальный максимум - первый элемент вектора
    int largest = numbers[0];

    // ищем максимум после ввода всех элементов
    for (int number : numbers)
    {
        if (number > largest)
        {
            largest = number;
        }
    }

    std::cout << "Наибольшее число: " << largest << "\n";
}
