#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

// Function prototypes
bool readMatrixFromFile(const std::string& filename, int matrix[MAX_SIZE][MAX_SIZE],int matrix2[MAX_SIZE][MAX_SIZE], int& size);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    std::string filename;
    std::cout << "Enter the file location with forward slashes: ";
    std::cin >> filename;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int size = 0;

    // Read matrix data from the file
    if (!readMatrixFromFile(filename, matrixA,matrixB, size)) {
        std::cerr << "Error: Failed to read matrix from the file." << std::endl;
        return 1;
    }


    // Display the matrices
    std::cout << "Blake Jesse\nLab #6: Matrix manipulation\n\n";
    std::cout << "Matrix A:\n";
    printMatrix(matrixA, size);
    std::cout << "\nMatrix B:\n";
    printMatrix(matrixB, size);

    // Add matrices and display the result
    int sumMatrix[MAX_SIZE][MAX_SIZE];
    addMatrices(matrixA, matrixB, sumMatrix, size);
    std::cout << "\nMatrix Sum (A + B):\n";
    printMatrix(sumMatrix, size);

    // Multiply matrices and display the result
    int productMatrix[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(matrixA, matrixB, productMatrix, size);
    std::cout << "\nMatrix Product (A * B):\n";
    printMatrix(productMatrix, size);

    // Subtract matrices and display the result
    int diffMatrix[MAX_SIZE][MAX_SIZE];
    subtractMatrices(matrixA, matrixB, diffMatrix, size);
    std::cout << "\nMatrix Difference (A - B):\n";
    printMatrix(diffMatrix, size);

    return 0;
}

// Function to read matrix data from a file
bool readMatrixFromFile(const std::string& filename, int matrix[MAX_SIZE][MAX_SIZE],int matrix2[MAX_SIZE][MAX_SIZE], int& size) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    if (!(file >> size)) {
        return false;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (!(file >> matrix[i][j])) {
                return false;
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (!(file >> matrix2[i][j])) {
                return false;
            }
        }
    }

    return true;
}

// Function to display a matrix
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

