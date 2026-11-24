#include <iostream>

int main()
{
    int matrix[10][10];
    int sorted[100];
    int rows;
    int columns;

    std::cout << "Количество строк (не более 10): ";
    std::cin >> rows;
    std::cout << "Количество столбцов (не более 10): ";
    std::cin >> columns;

    // проверяем что матрица помещается в массив
    if (rows < 1 || rows > 10 || columns < 1 || columns > 10)
    {
        std::cout << "Количество строк и столбцов должно быть от 1 до 10\n";
        return 0;
    }

    int count = rows * columns;

    std::cout << "Элементы матрицы:\n";

    // вводим матрицу и копируем ее элементы в одномерный массив
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cin >> matrix[i][j];
            sorted[i * columns + j] = matrix[i][j];
        }
    }

    // сортируем одномерный массив по возрастанию пузырьком
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (sorted[j] > sorted[j + 1])
            {
                int temporary = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temporary;
            }
        }
    }

    // границы еще не заполненной части матрицы
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = columns - 1;
    int index = 0;

    // заполняем матрицу по спирали, после каждой стороны сдвигаем границу
    while (top <= bottom && left <= right)
    {
        // верхняя строка слева направо
        for (int j = left; j <= right; j++)
        {
            matrix[top][j] = sorted[index];
            index++;
        }
        top++;

        // правый столбец сверху вниз
        for (int i = top; i <= bottom; i++)
        {
            matrix[i][right] = sorted[index];
            index++;
        }
        right--;

        // нижняя строка справа налево
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                matrix[bottom][j] = sorted[index];
                index++;
            }
            bottom--;
        }

        // левый столбец снизу вверх
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                matrix[i][left] = sorted[index];
                index++;
            }
            left++;
        }
    }

    std::cout << "\nМатрица по спирали:\n";

    // выводим матрицу
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}
