#include <iostream>

// функция из задания 1, максимум из двух чисел
int maximum(int first, int second)
{
    if (first > second)
    {
        return first;
    }

    return second;
}

// перегрузка, максимум элементов массива
// в параметрах количество элементов + массив переданный по имени
int maximum(int count, int numbers[])
{
    // начальный максимум - первый элемент массива
    int largest = numbers[0];

    for (int i = 1; i < count; i++)
    {
        // сравниваем через функцию для двух чисел
        largest = maximum(largest, numbers[i]);
    }

    return largest;
}

int main()
{
    int numbers[20];
    int count;

    std::cout << "Количество элементов (не более 20): ";
    std::cin >> count;

    // проверяем что количество помещается в массив
    if (count < 1 || count > 20)
    {
        std::cout << "Количество должно быть от 1 до 20\n";
        return 0;
    }

    // вводим массив
    for (int i = 0; i < count; i++)
    {
        std::cout << "Элемент: ";
        std::cin >> numbers[i];
    }

    // вызываем перегруженную функцию и выводим результат
    std::cout << "Наибольший элемент: " << maximum(count, numbers) << "\n";
}
