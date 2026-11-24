#include <iostream>
int main()
{
    setlocale(0, "");
    int age;
    age = 28;
    age++;
    age += 2;
    age = age + 3;
    std::cout << "age=" << age << std::endl;
    std::getchar();
}
