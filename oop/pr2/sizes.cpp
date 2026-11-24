#include <iostream>

int main()
{
    // создаем различные переменные
    int i = 1;
    double d = 1.5;
    char c = 'a';

    // получаем их адреса и создаем поинтеры
    int *pi = &i;
    double *pd = &d;
    char *pc = &c;

    // pi + 1 это адрес следующего int, разница адресов в байтах и есть размер
    // приводим к char*, потому что char занимает ровно 1 байт
    int intSize = (char *)(pi + 1) - (char *)pi;
    int doubleSize = (char *)(pd + 1) - (char *)pd;
    int charSize = (pc + 1) - pc; // уже является char

    // выводим адреса и размеры
    std::cout << "int:    адрес = " << pi << ", размер = " << intSize << " байт\n";
    std::cout << "double: адрес = " << pd << ", размер = " << doubleSize << " байт\n";
    // без void* cout примет char* за строку и напечатает символы вместо адреса
    std::cout << "char:   адрес = " << (void *)pc << ", размер = " << charSize << " байт\n";
}
