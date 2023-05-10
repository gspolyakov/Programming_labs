//#include <iostream>
//
//using namespace std;
//
//class Vector{
//
//private:
//    int size;
//    int* elements;
//
//public:
//    Vector(int* elems, int sz) {
//        size = sz;
//        elements = new int[size];
//        for (int i = 0; i < size; i++) {
//            elements[i] = elems[i];
//        }
//    }
//
//    Vector operator+(const Vector & other) const{
//        if (size == other.size) {
//            for (int i = 0; i < size; i++)
//                elements[i] += other.elements[i];
//        }
//        return Vector(elements, size);
//    };
//
//    Vector operator-(const Vector& other) const {
//        if (size == other.size) {
//            int* result = new int[size];
//            for (int i = 0; i < size; i++) {
//                result[i] = elements[i] - other.elements[i];
//            }
//            return Vector(result, size);
//        }
//    }
//
//    int operator*(const Vector & other) const{
//        int result = 0;
//        if (size == other.size) {
//            for (int i = 0; i < size; i++) {
//                result += (elements[i] * other.elements[i]);
//            }
//        }
//        return result;
//    };
//
//    Vector operator*(const int& num){
//        for(int i =0; i<size; i++){
//            elements[i]*=num;
//        }
//        return Vector(elements, size);
//    }
//
//    Vector operator/(const int& num) const {
//        if (num == 0) {
//            throw runtime_error("Cannot divide by zero!");
//        }
//        int* result = new int[size];
//        for (int i = 0; i < size; i++) {
//            result[i] = elements[i] / num;
//        }
//        return Vector(result, size);
//    }
//
//    void PrintVector(){
//        for (int i = 0; i < size; i++) {
//            cout << elements[i] << " ";
//        }
//        cout << endl;
//    }
//
//};
//
//int main(){
//    int s, n, x;
//    cin >> s;
//    cin >> n;
//    int* arr = new int[s];
//    for(int i=0; i<s; i++){
//        cin >> x;
//        arr[i] = x;
//    }
//    Vector vec_1 = Vector(arr, s);
//    Vector vec_2 = Vector(arr, s);
//    Vector vec_plus = vec_1+vec_2;
//    Vector vec_minus = vec_1-vec_2;
//    int vec_scalar = vec_1*vec_2;
//    Vector vec_prod = vec_1*n;
//    Vector vec_div = vec_1/n;
//
//    vec_plus.PrintVector();
//    vec_minus.PrintVector();
//    cout << vec_scalar << endl;
//    vec_prod.PrintVector();
//    vec_div.PrintVector();
//    return 0;
//}