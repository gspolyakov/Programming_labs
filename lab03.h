#include <iostream>
#include "lab02.h"

using namespace std;
class Matrix{

    friend Vector;

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

    Matrix operator*(Vector& other){
        int** result = new int*[columns];
        for(int i=0; i<columns; i++)
            result[i] = new int[1];

        for(int i = 0; i < columns; i++){
            for (int j = 0; j < rows; j++)
                result[i] += elements[i][j] * other.elements[i];

        }
        return {result, sizeof result, 1};
    }

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
