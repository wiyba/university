#include <iostream>

int main()
{
    // номер в списке группы
    int numberInList = 24;

    // создаем переменную и ее указатель
    int value = 10;
    int *pointer = &value;

    std::cout << "до: " << value << "\n";

    // увеличиваем переменную через указатель
    *pointer += numberInList;

    std::cout << "после: " << value << "\n";
}
