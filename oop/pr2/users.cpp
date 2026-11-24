#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    // без этого wcout не умеет выводить русские буквы
    setlocale(LC_ALL, "");

    // wstring вместо string - чтобы русская буква считалась за один символ при выравнивании таблицы
    std::wstring surname[3];
    std::wstring name[3];
    int years[3];
    int months[3];

    // вводим данные троих пользователей
    for (int i = 0; i < 3; i++)
    {
        std::wcout << L"Пользователь " << i+1 << L"\nФамилия, имя, лет, месяцев: "; // L делает строку широкой, для wcout
        std::wcin >> surname[i] >> name[i] >> years[i] >> months[i];
        std::wcout << L"\n";
    }

    // выводим шапку таблицы
    // setw задает ширину колонки
    std::wcout << std::left;
    std::wcout << std::setw(12) << L"Фамилия" << std::setw(12) << L"Имя" << std::setw(12) << L"Месяцев" << L"Дней\n";

    // считаем возраст и выводим строку таблицы для каждого
    for (int i = 0; i < 3; i++)
    {
        int ageInMonths = years[i] * 12 + months[i]; // в году 12 месяцев
        int ageInDays = ageInMonths * 30; // в месяце берем 30 дней

        std::wcout << std::setw(12) << surname[i] << std::setw(12) << name[i] << std::setw(12) << ageInMonths << ageInDays << L"\n";
    }
}
