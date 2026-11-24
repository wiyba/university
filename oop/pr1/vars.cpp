#include <iostream>

void print(int i, double d, bool b, char c)
{
    std::cout << "int = " << i << "\n";
    std::cout << "double = " << d << "\n";
    std::cout << "bool = " << b << "\n";
    std::cout << "char = " << c << "\n";
}

int main()
{
    // создаем переменные
    int i;
    double d;
    bool b;
    char c;

    // задаем значения переменным
    i = 10;
    d = 10.2;
    b = true;
    c = 103;

    // выводим переменные с начальным значением
    print(i, d, b, c);

    // уменьшаем все переменные на 1
    i -= 1;
    d -= 1;
    b -= 1;
    c -= 1;

    // выводим переменные после уменьшения на 1
    std::cout << "\nпосле уменьшения на 1\n\n";
    print(i, d, b, c);
}
