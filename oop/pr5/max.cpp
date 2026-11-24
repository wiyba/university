#include <iostream>

int main()
{
    int numbers[20];
    int count;

    std::cout << "Количество чисел (не более 20): ";
    std::cin >> count;

    // проверяем, что количество помещается в массив
    if (count < 1 || count > 20)
    {
        std::cout << "Количество должно быть от 1 до 20\n";
        return 0;
    }

    // записываем числа в массив
    for (int i = 0; i < count; i++)
    {
        std::cout << "Число: ";
        std::cin >> numbers[i];
    }

    // начальный максимум -- первый элемент массива
    int largest = numbers[0];
    int largestIndex = 0;

    // ищем наибольшее число после ввода
    for (int i = 1; i < count; i++)
    {
        if (numbers[i] > largest)
        {
            largest = numbers[i];
            largestIndex = i;
        }
    }

    // номер считаем с единицы
    std::cout << "Наибольшее число: " << largest << "\n";
    std::cout << "Его номер в массиве: " << largestIndex + 1 << "\n";
}
