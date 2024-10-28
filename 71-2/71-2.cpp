#include <iostream>
#include <iomanip>
using namespace std;

void generateMatrix(int** matrix, int rows, int cols, int min, int max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = min + (rand() % (max - min + 1));
        }
    }
}

void calculateAndReplace(int** matrix, int rows, int cols, int& count, int& sum, int i = 0, int j = 0) {
    if (i >= rows) return;

    if (j >= cols) {
        calculateAndReplace(matrix, rows, cols, count, sum, i + 1, 0);
        return;
    }

    if (matrix[i][j] > 0 && (i % 3 != 0) && (j % 3 != 0)) {
        count++;
        sum += matrix[i][j];
        matrix[i][j] = 0;
    }

    calculateAndReplace(matrix, rows, cols, count, sum, i, j + 1);
}

void recursiveSort(int** matrix, int rows, int cols, int* indices, int start = 0) {
    if (start >= cols - 1) return;

    for (int j = 0; j < cols - start - 1; j++) {
        if (matrix[0][indices[j]] > matrix[0][indices[j + 1]]) {
            int temp = indices[j];
            indices[j] = indices[j + 1];
            indices[j + 1] = temp;
        }
        else if (matrix[0][indices[j]] == matrix[0][indices[j + 1]]) {
            if (matrix[1][indices[j]] > matrix[1][indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
            else if (matrix[1][indices[j]] == matrix[1][indices[j + 1]]) {
                if (matrix[2][indices[j]] < matrix[2][indices[j + 1]]) {
                    int temp = indices[j];
                    indices[j] = indices[j + 1];
                    indices[j + 1] = temp;
                }
            }
        }
    }

    recursiveSort(matrix, rows, cols, indices, start + 1);
}

void printMatrix(int** matrix, int rows, int cols) {
    cout << fixed << setprecision(2);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int rows = 7;
    const int cols = 5;
    const int min = -6;
    const int max = 31;
    int count = 0, sum = 0;

    srand(42);

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    generateMatrix(matrix, rows, cols, min, max);
    cout << "Original Matrix:\n";
    printMatrix(matrix, rows, cols);

    calculateAndReplace(matrix, rows, cols, count, sum);
    cout << "\nModified Matrix:\n";
    printMatrix(matrix, rows, cols);
    cout << "Count of positive elements: " << count << endl;
    cout << "Sum of positive elements: " << sum << endl;

    int* indices = new int[cols];
    for (int i = 0; i < cols; i++) {
        indices[i] = i;
    }

    recursiveSort(matrix, rows, cols, indices);

    int** sortedMatrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        sortedMatrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            sortedMatrix[i][j] = matrix[i][indices[j]];
        }
    }

    cout << "\nSorted Matrix:\n";
    printMatrix(sortedMatrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
        delete[] sortedMatrix[i];
    }
    delete[] matrix;
    delete[] sortedMatrix;
    delete[] indices;

    return 0;
}
