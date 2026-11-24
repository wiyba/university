#include <iostream>
#include <string>

class Flower
{
    // поля
    std::string name;
    std::string color;
    double price;

  public:
    // конструктор без параметров
    Flower() : name("Роза"), color("красный"), price(150)
    {
    }

    // конструктор с двумя параметрами
    Flower(std::string name, double price) : name(name), color("белый"), price(price)
    {
    }

    // конструктор с тремя параметрами
    Flower(std::string name, std::string color, double price) : name(name), color(color), price(price)
    {
    }

    // функция класса
    void print()
    {
        std::cout << name << ", цвет: " << color << ", цена: " << price << " руб.\n";
    }

    // перегрузка функции print
    void print(int count)
    {
        std::cout << name << ", цвет: " << color << ", количество: " << count << " шт.\n";
    }

    // функция с входным параметром и возвращаемым значением
    double cost(int count)
    {
        return price * count;
    }
};

int main()
{
    // создаем объекты тремя разными конструкторами
    Flower rose;
    Flower chamomile("Ромашка", 60);
    Flower tulip("Тюльпан", "желтый", 90);

    // вызываем функцию класса
    rose.print();
    chamomile.print();
    tulip.print();

    int count;

    std::cout << "\nКоличество тюльпанов в букете: ";
    std::cin >> count;

    if (count < 1)
    {
        std::cout << "Количество должно быть не меньше 1\n";
        return 0;
    }

    // вызываем перегруженную функцию и функцию с возвращаемым значением
    tulip.print(count);
    std::cout << "Стоимость букета: " << tulip.cost(count) << " руб.\n";
}
