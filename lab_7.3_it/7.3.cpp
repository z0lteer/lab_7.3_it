#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int size, const int Low, const int High) {
    // Заповнення матриці випадковими числами
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int size) {
    // Виведення матриці
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void ShiftRight(int** a, const int size, int k) {
    // Циклічне зміщення матриці вправо на k елементів
    for (int shift = 0; shift < k; shift++) {
        int temp = a[0][0];
        int i = 0, j = 0;

        // Переміщення першого рядка
        for (j = 0; j < size - 1; j++)
            a[i][j] = a[i][j + 1];

        // Переміщення останнього стовпця
        for (i = 0; i < size - 1; i++)
            a[i][size - 1] = a[i + 1][size - 1];

        // Переміщення останнього рядка
        for (j = size - 1; j > 0; j--)
            a[size - 1][j] = a[size - 1][j - 1];

        // Переміщення першого стовпця
        for (i = size - 1; i > 1; i--)
            a[i][0] = a[i - 1][0];

        a[1][0] = temp;  // Вставка тимчасового елемента
    }
}

int FindColumnWithMostZeros(int** a, const int size) {
    // Пошук стовпця з найбільшою кількістю нульових елементів
    int maxZeroCount = 0;
    int columnWithMaxZeros = -1;

    for (int j = 0; j < size; j++) {
        int zeroCount = 0;
        for (int i = 0; i < size; i++) {
            if (a[i][j] == 0)
                zeroCount++;
        }
        if (zeroCount > maxZeroCount) {
            maxZeroCount = zeroCount;
            columnWithMaxZeros = j;
        }
    }

    return columnWithMaxZeros;
}

int main() {
    srand((unsigned)time(NULL));
    int size, Low = -9, High = 9, k;

    cout << "Enter matrix size: ";
    cin >> size;
    cout << "Enter number of shifts: ";
    cin >> k;

    int** a = new int* [size];
    for (int i = 0; i < size; i++)
        a[i] = new int[size];

    Create(a, size, Low, High);
    cout << "Original matrix:" << endl;
    Print(a, size);

    ShiftRight(a, size, k);
    cout << "Shifted matrix:" << endl;
    Print(a, size);

    int colWithMostZeros = FindColumnWithMostZeros(a, size);
    if (colWithMostZeros != -1)
        cout << "Column with the most zeros: " << colWithMostZeros << endl;
    else
        cout << "No zeros found in any column." << endl;

    for (int i = 0; i < size; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
