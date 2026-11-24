#include <iostream>
#include <string>
#include <vector>

int main()
{
    int count;

    std::cout << "Количество строк: ";
    std::cin >> count;

    // создаем пустой вектор строк
    std::vector<std::string> lines;

    for (int i = 0; i < count; i++)
    {
        std::string line;

        // вводим строку целиком, ws пропускает перевод строки от прошлого ввода
        std::cout << "Строка: ";
        std::getline(std::cin >> std::ws, line);

        // ищем место вставки - первую строку, которая не меньше введенной
        size_t position = 0;

        while (position < lines.size() && lines[position] < line)
        {
            position++;
        }

        // вставляем строку в найденное место, вектор остается упорядоченным
        lines.insert(lines.begin() + position, line);
    }

    std::cout << "\nПо алфавиту:\n";

    // выводим результат
    for (std::string line : lines)
    {
        std::cout << line << "\n";
    }
}
