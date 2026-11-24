#include <iostream>

int main()
{
    int firstLogin = 1001;
    int firstPassword = 1234;
    int secondLogin = 1002;
    int secondPassword = 5678;

    int attempts = 3;

    for (int i = 1; i <= attempts; i++)
    {
        int login;
        int password;

        std::cout << "Логин: ";
        std::cin >> login;
        std::cout << "Пароль: ";
        std::cin >> password;

        bool isFirstUser = login == firstLogin && password == firstPassword;
        bool isSecondUser = login == secondLogin && password == secondPassword;

        if (isFirstUser || isSecondUser)
        {
            std::cout << "Вход выполнен\n";
            return 0;
        }

        std::cout << "Неверный логин или пароль, осталось попыток: " << attempts - i << "\n";
    }

    std::cout << "Доступ запрещен\n";
}
