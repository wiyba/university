#include <iostream>

// выделяет память под матрицу size на size
double **createMatrix(int size)
{
    // массив указателей на строки
    double **matrix = new double *[size];

    // память под каждую строку
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new double[size];
    }

    return matrix;
}

// освобождает память матрицы
void deleteMatrix(double **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

// рекурсивная функция, определитель разложением по первой строке
double determinant(double **matrix, int size)
{
    // условие выхода из рекурсии
    if (size == 1)
    {
        return matrix[0][0];
    }

    // память под минор, на единицу меньше исходной матрицы
    double **minor = createMatrix(size - 1);
    double result = 0;
    int sign = 1;

    for (int column = 0; column < size; column++)
    {
        // заполняем минор - матрица без первой строки и столбца column
        for (int i = 1; i < size; i++)
        {
            int minorColumn = 0;

            for (int j = 0; j < size; j++)
            {
                if (j != column)
                {
                    minor[i - 1][minorColumn] = matrix[i][j];
                    minorColumn++;
                }
            }
        }

        // рекурсивный вызов для минора, знак чередуется
        result += sign * matrix[0][column] * determinant(minor, size - 1);
        sign = -sign;
    }

    deleteMatrix(minor, size - 1);

    return result;
}

int main()
{
    int size;

    std::cout << "Размерность матрицы: ";
    std::cin >> size;

    if (size < 1)
    {
        std::cout << "Размерность должна быть не меньше 1\n";
        return 0;
    }

    // выделяем память под матрицу
    double **matrix = createMatrix(size);

    std::cout << "Элементы матрицы:\n";

    // вводим матрицу
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Определитель: " << determinant(matrix, size) << "\n";

    // освобождаем память
    deleteMatrix(matrix, size);
}
