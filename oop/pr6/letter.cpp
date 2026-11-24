#include <iostream>
#include <string>

int main()
{
    // без этого wcin и wcout не умеют работать с русскими буквами
    setlocale(LC_ALL, "");

    // первая буква фамилии, заглавная и строчная
    wchar_t upper = L'Ш';
    wchar_t lower = L'ш';

    std::wstring line;

    // вводим строку целиком, вместе с пробелами
    std::wcout << L"Строка: ";
    std::getline(std::wcin, line);

    int count = 0;

    // перебираем символы строки и считаем вхождения буквы
    for (wchar_t symbol : line)
    {
        if (symbol == upper || symbol == lower)
        {
            count++;
        }
    }

    std::wcout << L"Количество букв " << upper << L": " << count << L"\n";
}
