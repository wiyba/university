#include <iostream>

// функция ввода, параметры переданы по ссылке
// введенные значения попадают в переменные из main
void input(int &first, int &second)
{
    std::cout << "Первое число: ";
    std::cin >> first;
    std::cout << "Второе число: ";
    std::cin >> second;
}

int main()
{
    int first;
    int second;

    // вызываем функцию ввода
    input(first, second);

    // ищем наибольшее число в main
    int largest = first;

    if (second > largest)
    {
        largest = second;
    }

    std::cout << "Наибольшее число: " << largest << "\n";
}
