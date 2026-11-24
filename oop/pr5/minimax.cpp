#include <iostream>

int main()
{
    int matrix[20][20];
    int rows;
    int columns;

    std::cout << "Количество строк (не более 20): ";
    std::cin >> rows;
    std::cout << "Количество столбцов (не более 20): ";
    std::cin >> columns;

    // проверяем что матрица помещается в массив
    if (rows < 1 || rows > 20 || columns < 1 || columns > 20)
    {
        std::cout << "Количество строк и столбцов должно быть от 1 до 20\n";
        return 0;
    }

    std::cout << "Элементы матрицы:\n";

    // вводим матрицу
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    int minimax = matrix[0][0];

    for (int i = 0; i < rows; i++)
    {
        // ищем минимум в строке
        int smallest = matrix[i][0];

        for (int j = 1; j < columns; j++)
        {
            if (matrix[i][j] < smallest)
            {
                smallest = matrix[i][j];
            }
        }

        // выбираем максимум среди минимумов строк
        if (i == 0 || smallest > minimax)
        {
            minimax = smallest;
        }
    }

    std::cout << "Минимакс: " << minimax << "\n";
}
