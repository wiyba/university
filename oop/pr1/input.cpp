#include <iostream>

int main()
{
    // создаем переменные
    int i;
    double d;
    bool b;
    char c;

    std::cout << "Введите целое число: ";
    std::cin >> i; // получаем int
    std::cout << "Введите дробное число: ";
    std::cin >> d; // получаем double
    std::cout << "Введите логическое значение (0 или 1): ";
    std::cin >> b; // получаем bool
    std::cout << "Введите символ: ";
    std::cin >> c; // получаем char

    // выводим полученное
    std::cout << "\n";
    std::cout << "int = " << i << "\n";
    std::cout << "double = " << d << "\n";
    std::cout << "bool = " << b << "\n";
    std::cout << "char = " << c << "\n";
}
