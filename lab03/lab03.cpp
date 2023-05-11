#include <iostream>

using namespace std;

class Matrix{

private:
    int rows;
    int columns;
    int** elements;

public:
    Matrix(int** elems, int row, int col) {
        rows = row;
        columns = col;
        elements = new int*[columns];
        for (int i = 0; i < rows; i++) {
            elements[i] = new int[rows];
        }
        for (int i = 0; i < columns; i++) {
            for (int j = 0; j < rows; j++) {
                elements[i][j] = elems[i][j];
                cout << elements[i][j] << endl;
            }

        }
    }

    Matrix operator+(const Matrix & other) const{
        if (columns == other.columns and rows == other.rows) {
            int** result = new int*[columns];
            for (int i = 0; i < rows; i++) {
                result[i] = new int[rows];
            }
            for (int i = 0; i < columns; i++){
                for (int j = 0; j < rows; j++){
                    result[i][j] = elements[i][j] + other.elements[i][j];
                }
            }
        return {result, rows, columns};
        } else{
            throw runtime_error("Operation cannot be performed");
        }
    };

    Matrix operator-(const Matrix& other) const {
        if (columns == other.columns and rows == other.rows) {
            int** result = new int*[columns];
            for (int i = 0; i < rows; i++) {
                result[i] = new int[rows];
            }
            for (int i = 0; i < columns; i++) {
                for (int j = 0; j < columns; j++) {
                result[i][j] -= other.elements[i][j];
                }
            }
            return {result, rows, columns};
        } else{
            throw runtime_error("Operation cannot be performed");
        }
    };

    int operator*(const Matrix & other) const{
        int result = 0;
        if (columns == other.columns and rows == other.rows) {
            for (int i = 0; i < columns; i++) {
                for (int j = 0; j < columns; j++) {
                result += (elements[i][j] * other.elements[i][j]);
                }
            }
            return result;
        } else{
            throw runtime_error("Operation cannot be performed");
        }

    };

    Matrix operator*(const int& num){
        int** result = new int*[columns];
        for (int i = 0; i < rows; i++) {
            result[i] = new int[rows];
        }
        for(int i = 0; i < columns; i++){
            for (int j = 0; j<rows; j++){
                result[i][j] = elements[i][j]*num;
            }
        }
        return {result, rows, columns};
    }

    Matrix operator/(const int& num) const {
        if (num == 0) {
            throw runtime_error("Cannot divide by zero!");
        }
        int** result = new int*[columns];
        for (int i = 0; i < rows; i++) {
            result[i] = new int[rows];
        }
        for (int i = 0; i < columns; i++) {
            for (int j=0; j<rows; j++) {
                result[i][j] = elements[i][j] / num;
            }
        }
        return {result, rows, columns};
    }

    void PrintMatrix(){
        cout << "---" << endl;
        for (int i = 0; i < columns; i++) {
            for (int j = 0; j < rows; j++) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
        cout << "---" << endl;
    }

};

int main(){
    int col, row, n, x;
    cin >> col;
    cin >> row;
    cin >> n;
    int** arr = new int*[col];
    for(int i=0; i<col; i++){
        arr[i] = new int[row];
    }
    for(int i=0; i<col; i++){
        for (int j=0; j < row; j++){
            cin >> x;
            arr[i][j] = x;
        }
    }

    Matrix matrix_1 = Matrix(arr, row, col);
    Matrix matrix_2 = Matrix(arr, row, col);
    Matrix matrix_plus = matrix_1+matrix_2;
    Matrix matrix_minus = matrix_1-matrix_2;
    int matrix_scalar = matrix_1*matrix_2;
    Matrix matrix_prod = matrix_1*n;
    Matrix matrix_div = matrix_1/n;

    matrix_1.PrintMatrix();

    matrix_plus.PrintMatrix();
    matrix_minus.PrintMatrix();
    cout << matrix_scalar << endl;
    matrix_prod.PrintMatrix();
    matrix_div.PrintMatrix();
    return 0;
}