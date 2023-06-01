#include "iostream"
using namespace std;

class Vector;

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

    Vector operator*(const Vector& other);

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

class Vector{

    friend Matrix;

private:

    int size;
    int* elements;

public:

    Vector(const int* elems, int sz) {
        size = sz;
        elements = new int[size];
        for (int i = 0; i < size; i++) {
            elements[i] = elems[i];
        }
    }

    Vector operator*(const Matrix & other) const{
        int* result = new int[size];
        if (size == other.columns) {
            for (int i = 0; i < size; i++) {
                int sum = 0;
                for (int j = 0; j < other.rows; j++) {
                    result[i] += elements[i] * other.elements[i][j];
                }
            }
            return {result, size};
        }
    }

    void PrintVector(){
        for (int i = 0; i < size; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

Vector Matrix::operator* (const Vector &other) {
    int* result = new int[columns];
    if(columns == other.size){
        for(int i = 0; i < columns; i++){
            for (int j = 0; j < rows; j++)
                result[i] += elements[i][j] * other.elements[i];
        }
        return {result, columns};
    }
}

int main(){
    int i, j;
    cin >> i;
    cin >> j;
    cout << "input matrix" << endl;
    int** arr = new int*[i];
    for (int a=0; a<i; a++) {
        arr[a] = new int[j];
        for (int b=0; b<j; b++){
            cin >> arr[a][b];
        }
    }
    cout << "input vector" << endl;
    int* a = new int[i];
    for (int b=0; b<i; b++){
        cin >> a[b];
    }
    Matrix m = Matrix(arr, j, i);
    Vector v = Vector(a, i);
    Vector b = m * v;
    Vector c = v * m;
    m.PrintMatrix();
    v.PrintVector();
    b.PrintVector();
    c.PrintVector();
    return 0;
}