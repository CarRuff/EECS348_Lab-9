#include <iostream>
#include "matrix.hpp"

int main() {
    // Opem Input File
    std::ifstream infile("input.txt");
    if (!infile) {
        std::cerr << "Cannot open file.\n";
        return 1;
    }
    
    // Setup variables
    int N, type_flag;
    // Read Matrix size and data type
    infile >> N >> type_flag;
    
    // If its a int matrix
    if (type_flag == 0) {
        
        // Declare int
        Matrix<int> A(N), B(N);
        // Read matrices 
        infile >> A >> B;
        
        // Print both
        std::cout << "Matrix A:\n" << A;
        std::cout << "Matrix B:\n" << B;
        
        // Add and print
        Matrix<int> C = A + B;
        std::cout << "A + B:\n" << C;
        
        // Multiply and print
        Matrix<int> D = A * B;
        std::cout << "A * B:\n" << D;
        
        // Get diagonal sum and Secondary sum
        auto diagSums = A.diagonalSums();
        auto main_diag = diagSums.first;
        auto sec_diag = diagSums.second;
        std::cout << "Main diagonal sum: " << main_diag << "\n";
        std::cout << "Secondary diagonal sum: " << sec_diag << "\n";
        
        // Swap row 0 and 1
        A.swapRows(0, 1);
        std::cout << "After swapping row 0 and 1:\n" << A;
        
        // Swap column 0 and 1
        A.swapCols(0, 1);
        std::cout << "After swapping col 0 and 1:\n" << A;
        
        // Update row 2, col 2 to 99
        A.update(2, 2, 99);
        std::cout << "After updating A[2][2] to 99:\n" << A;
    
    // If Double matrix
    } else if (type_flag == 1) {
        
        // Declare double
        Matrix<double> A(N), B(N);
        // Read matrices
        infile >> A >> B;
        
        // Print both
        std::cout << "Matrix A:\n" << A;
        std::cout << "Matrix B:\n" << B;
        
        // Print addition
        Matrix<double> C = A + B;
        std::cout << "A + B:\n" << C;
    
        // Print product
        Matrix<double> D = A * B;
        std::cout << "A * B:\n" << D;

        // Get diagonal sum and Secondary sum
        auto diagSums = A.diagonalSums();
        auto main_diag = diagSums.first;
        auto sec_diag = diagSums.second;
        std::cout << "Main diagonal sum: " << main_diag << "\n";
        std::cout << "Secondary diagonal sum: " << sec_diag << "\n";
        
        // Swap row 0 and 1
        A.swapRows(0, 1);
        std::cout << "After swapping row 0 and 1:\n" << A;
        
        // Swap col 0 and 1
        A.swapCols(0, 1);
        std::cout << "After swapping col 0 and 1:\n" << A;
        
        // update row 2, col 2 to 99
        A.update(2, 2, 99.5);
        std::cout << "After updating A[2][2] to 99.5:\n" << A;
    
    // any other type
    } else {
        // Print error
        std::cerr << "Invalid type flag. Use 0 for int or 1 for double.\n";
        return 1;
    }

    return 0;
}
