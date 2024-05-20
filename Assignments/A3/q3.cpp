#include <iostream>
using namespace std;

template<typename T> 
class Matrix {
protected:
    int cols;
    int rows;
    T **mat;

public:
    Matrix(int cols, int rows) : cols(cols), rows(rows) {
        mat = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new T[cols];
            for (int j = 0; j < cols; ++j)
                mat[i][j] = T();
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] mat[i];
        delete[] mat;
    }

    T get(int row, int col) const {
        return mat[row][col];
    }

    void set(int row, int col, T val) {
        mat[row][col] = val;
    }

    virtual void display() const {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) {
        Matrix<T> result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                result.set(i, j, this->get(i, j) + other.get(i, j));
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) {
        Matrix<T> result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                result.set(i, j, this->get(i, j) - other.get(i, j));
        }
        return result;
    }

    Matrix<T> operator*(Matrix<T>& other) {
        Matrix<T> result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                result.set(i, j, this->get(i, j) * other.get(i, j));
        }
        return result;
    }
};

template <typename T>
class IntMatrix : public Matrix<int> {
public:
    IntMatrix(int r, int c) : Matrix<int>(c, r) {}

    void display() const override {
        cout << "Int ";
        Matrix<int>::display();
    }
};

template <typename T>
class DoubleMatrix : public Matrix<double> {
public:
    DoubleMatrix(int r, int c) : Matrix<double>(c, r) {}

    void display() const override {
        cout << "Double ";
        Matrix<double>::display();
    }
};

int main() {
    cout << "Name: Hafsa Rashid" << endl << "Student ID: 23K-0064" << endl;
    cout << "\n";

    IntMatrix<int> intMat(2, 2);
    intMat.set(0, 0, 2);
    intMat.set(0, 1, 3);
    intMat.set(1, 0, 4);
    intMat.set(1, 1, 5);
    intMat.display();

    IntMatrix<int> intMat2(2, 2);
    intMat2.set(0, 0, 1);
    intMat2.set(0, 1, 2);
    intMat2.set(1, 0, 3);
    intMat2.set(1, 1, 4);
    intMat2.display();

    DoubleMatrix<double> doubleMat(2, 2);
    doubleMat.set(0, 0, 1.1);
    doubleMat.set(0, 1, 2.2);
    doubleMat.set(1, 0, 3.3);
    doubleMat.set(1, 1, 4.4);
    doubleMat.display();

    DoubleMatrix<double> doubleMat2(2, 2);
    doubleMat2.set(0, 0, 4.0);
    doubleMat2.set(0, 1, 2.0);
    doubleMat2.set(1, 0, 1.0);
    doubleMat2.set(1, 1, 0.5);
    doubleMat2.display();

    // perfroming matrix operations with the defined matrices
    (intMat + intMat2).display();
    (intMat2 - intMat).display();
    (doubleMat * doubleMat2).display();

    return 0;
}


