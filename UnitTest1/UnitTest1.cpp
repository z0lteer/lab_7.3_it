#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.3_it/7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int size = 3;
            const int Low = -9;
            const int High = 9;
            int** matrix = new int* [size];
            for (int i = 0; i < size; i++)
                matrix[i] = new int[size];

            // Викликаємо функцію Create для заповнення матриці
            Create(matrix, size, Low, High);

            // Перевіряємо, чи всі елементи знаходяться в межах [Low, High]
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    Assert::IsTrue(matrix[i][j] >= Low && matrix[i][j] <= High, L"Value out of bounds");
                }
            }

            // Очищаємо пам'ять
            for (int i = 0; i < size; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    };
}