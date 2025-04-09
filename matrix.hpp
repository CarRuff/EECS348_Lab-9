#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <type_traits>
#include <stdexcept>

// Template For matrix
template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    int size;

public:
    // Initialize size and storage
    Matrix(int n) : size(n), data(n, std::vector<T>(n)) {}
    
    // GetSize Returns size
    int getSize() const { return size; }
    
    // Row Access
    std::vector<T>& operator[](int i) { return data[i]; }
    const std::vector<T>& operator[](int i) const { return data[i]; }

    // Overloaded stream operators
    friend std::istream& operator>>(std::istream& is, Matrix<T>& m) {
        for (int i = 0; i < m.size; ++i)
            for (int j = 0; j < m.size; ++j)
                is >> m.data[i][j];
        return is;
    }
    
    //  Print Matrix Elements for columns
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& m) {
        for (const auto& row : m.data) {
            for (const auto& val : row) {
                os << std::setw(8) << static_cast<double>(val);
            }
            os << '\n';
        }
        return os;
    }

    // Addition
    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result[i][j] = data[i][j] + other[i][j];
        return result;
    }

    // Multiplication
    Matrix<T> operator*(const Matrix<T>& other) const {
        Matrix<T> result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                for (int k = 0; k < size; ++k)
                    result[i][j] += data[i][k] * other[k][j];
        return result;
    }

    // Diagonal sums
    std::pair<T, T> diagonalSums() const {
        T main_diag = 0, secondary_diag = 0;
        for (int i = 0; i < size; ++i) {
            main_diag += data[i][i];
            secondary_diag += data[i][size - 1 - i];
        }
        return {main_diag, secondary_diag};
    }

    // Row swap
    void swapRows(int r1, int r2) {
        if (r1 >= 0 && r1 < size && r2 >= 0 && r2 < size)
            std::swap(data[r1], data[r2]);
    }

    // Column swap
    void swapCols(int c1, int c2) {
        if (c1 >= 0 && c1 < size && c2 >= 0 && c2 < size) {
            for (int i = 0; i < size; ++i)
                std::swap(data[i][c1], data[i][c2]);
        }
    }

    // Update using template
    template<typename U>
    void update(int row, int col, U value) {
        if (row >= 0 && row < size && col >= 0 && col < size)
            data[row][col] = static_cast<T>(value);
    }
};
