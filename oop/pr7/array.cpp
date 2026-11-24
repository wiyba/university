#include <iostream>

// функция ввода
// массив передан по имени, количество элементов по ссылке
void input(int numbers[], int &count)
{
    std::cout << "Количество элементов (не более 20): ";
    std::cin >> count;

    // при неверном количестве возвращаем пустой массив
    if (count < 1 || count > 20)
    {
        std::cout << "Количество должно быть от 1 до 20\n";
        count = 0;
        return;
    }

    // вводим массив
    for (int i = 0; i < count; i++)
    {
        std::cout << "Элемент: ";
        std::cin >> numbers[i];
    }
}

int main()
{
    int numbers[20];
    int count;

    // вызываем функцию, она заполняет массив и количество
    input(numbers, count);

    // выводим массив в main
    std::cout << "Количество элементов: " << count << "\n";
    std::cout << "Массив:";

    for (int i = 0; i < count; i++)
    {
        std::cout << " " << numbers[i];
    }

    std::cout << "\n";
}
