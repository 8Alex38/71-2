#include "pch.h"
#include "CppUnitTest.h"
#include "../71-2/71-2.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(MatrixTests)
    {
    public:
        TEST_METHOD(TestMatrixGeneration)
        {
            const int rows = 7;
            const int cols = 5;
            int** matrix = new int* [rows];
            for (int i = 0; i < rows; i++) {
                matrix[i] = new int[cols];
            }

            generateMatrix(matrix, rows, cols, -6, 31);

            bool isValid = true;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (matrix[i][j] < -6 || matrix[i][j] > 31) {
                        isValid = false;
                        break;
                    }
                }
            }

            if (isValid) {
                std::cout << "Matrix generation test passed." << std::endl;
            }
            else {
                std::cout << "Matrix generation test failed." << std::endl;
            }

            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        TEST_METHOD(TestCalculateAndReplace)
        {
            const int rows = 7;
            const int cols = 5;
            int** matrix = new int* [rows];
            for (int i = 0; i < rows; i++) {
                matrix[i] = new int[cols] {0, 1, 2, 3, 4}; 
            }

            int count = 0, sum = 0;
            calculateAndReplace(matrix, rows, cols, count, sum);

            std::cout << "Count of modified elements: " << count << std::endl;
            std::cout << "Sum of modified elements: " << sum << std::endl;

            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        TEST_METHOD(TestRecursiveSort)
        {
            const int rows = 3;
            const int cols = 5;
            int** matrix = new int* [rows];
            for (int i = 0; i < rows; i++) {
                matrix[i] = new int[cols];
            }

            matrix[0][0] = 3; matrix[0][1] = 1; matrix[0][2] = 2; matrix[0][3] = 4; matrix[0][4] = 5;
            matrix[1][0] = 8; matrix[1][1] = 7; matrix[1][2] = 6; matrix[1][3] = 9; matrix[1][4] = 10;
            matrix[2][0] = 15; matrix[2][1] = 12; matrix[2][2] = 11; matrix[2][3] = 14; matrix[2][4] = 13;

            int* indices = new int[cols];
            for (int i = 0; i < cols; i++) {
                indices[i] = i; 
            }

            recursiveSort(matrix, rows, cols, indices);

            std::cout << "Sorted Matrix:" << std::endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << std::endl;
            }

            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            delete[] indices;
        }
    };
}
