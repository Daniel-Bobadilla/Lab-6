#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void read(const string& file_name, int matrix1[][3], int matrix2[][3])
{
    // Initialize row counter variable
    int row_counter = 0;

    // Opening file
    ifstream file(file_name);

    // Creating a double for loop to store matrix1 content
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            file >> matrix1[i][j];
        }
    }

    file.seekg(18, ios::beg);

    // Creating a double for loop to store matrix2 content
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            file >> matrix2[i][j];
        }
    }

    // Closing file
    file.close();
}

void add_matrices(int matrix1[][3], int matrix2[][3], int result[][3]) 
{
    // Double for loop to add each value from both matrix1 and matrix2 and insert solution in designated position in result matrix
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void print_matrix(int matrix[][3]) 
{
    // Double for loop to print each value from the 2D array in a friendly format
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j == 2) {
                cout << matrix[i][j] << endl;
            } else {
                cout << matrix[i][j] << " ";
            }
        }
    }
}

void multiply_matrices(int matrix1[][3], int matrix2[][3], int result[][3]) 
{
    /* 
    Triple for loop to iterate through both matrices individually.
    Matrix1 is row by row. Matrix2 is column by column.
    Once value is determined it is stored in a temp which later used to
    store the resulting value into designated slot in result matrix.
    */
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int temp = 0;
            for (int k = 0; k < 3; ++k) {
                temp = temp + matrix1[i][k] * matrix2[k][j];
            }
        result[i][j] = temp;
        }
    }
}

void subtract_matrices(int matrix1[][3], int matrix2[][3], int result[][3])
{
    // Double for loop to subtract matrix2 values by matrix1 values and stores into result matrix
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = matrix2[i][j] - matrix1[i][j];
        }
    }
}

void change_matrix_value(int matrix1[][3])
{
    // Initialize row, column, and val variables
    int row;
    int column;
    int val;

    // Take a value from the user for row selection
    cout << "Choose a row 1-3:\n";
    cin >> row;

    // Take a value from the user for column selection
    cout << "\nChoose a column 1-3:\n";
    cin >> column;

    // Take value from user that will be replacing value from chosen matrix1 spot
    cout << "\nChoose a value:\n";
    cin >> val;

    // Accounts for user position and aligns correctly. Takes given value to replace chosen location value.
    matrix1[row - 1][column - 1] = val;
}

void matrix_max(int matrix1[][3])
{
    // Initialize max variable to store maximum value from matrix
    int max = 0;

    // Double for loop uses if statement to check each value from matrix and always store the largest value into "max"
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrix1[i][j] > max) {
                max = matrix1[i][j];
            }
        }        
    }
    // Output the value of "max"
    cout << max;
}

void transpose_matrix(int matrix1[][3])
{
    // Create a temporary matrix to be used later
    int temp_matrix[3][3] = {}; 

    // Double for loop makes copy of matrix1 into temp_matrix
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            temp_matrix[i][j] = matrix1[i][j];
        }
    }

    // Double for loop takes temp_matrix and stores its rows and columns in matrix1 to complete transpose
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix1[j][i] = temp_matrix[i][j];
        }
    }
}

int main()
{
    // Title and first question.
    cout << "LAB 6\n\n1. Read values from a file into a matrix: \n\n";

    // Name of file being used
    string file_name = "matrix_input.txt";

    // Matrix arrays stored in allocated memory
    int matrix1[3][3] = {};
    int matrix2[3][3] = {};
    int result[3][3] = {};

    // Meant to read matrix and store it into a 2D array.
    read(file_name, matrix1, matrix2);
    cout << "Complete!\n\n";

    // Prints second question and matrix values
    cout << "2. Print a Matrix:\n";
    cout << "\nMatrix 1:" << endl;
    print_matrix(matrix1);
    cout << "\nMatrix 2:" << endl;
    print_matrix(matrix2);

    // Prints third question and the solution
    cout << "\n3. Add two matrices and place the result in a third matrix; print the result:\n\n";
    add_matrices(matrix1, matrix2, result);
    cout << "Resulting Matrix\n";
    print_matrix(result);

    // Prints fourth question and the solution
    cout << "\n4. Multiply two matrices and place the result in a third matrix; print the result:\n\n";
    cout << "Resulting Matrix\n";
    multiply_matrices(matrix1, matrix2, result);
    print_matrix(result);

    // Prints fifth question and the solution
    cout << "\n5. Subtract the second matrix from the first matrix and place the result in a third matrix; print the result:\n\n";
    cout << "Resulting Matrix\n";
    subtract_matrices(matrix1, matrix2, result);
    print_matrix(result);

    // Prints sixth question and the solution
    cout << "\n6. Update an element of the first matrix; print the result:\n\n";
    change_matrix_value(matrix1);
    cout << "\nResulting Matrix\n";
    print_matrix(matrix1);

    // Prints the seventh question and the solution
    cout << "\n7. Get the max value of the first matrix:\n\n";
    matrix_max(matrix1);

    // Prints the eigth question and the solution
    cout << "\n\n8. Transpose the first matrix; print the result:\n\n";
    transpose_matrix(matrix1);
    cout << "Resulting Matrix\n";
    print_matrix(matrix1);
}
