#include "SparseMatrix.hpp"
#include "SparseVector.hpp"

using namespace std;

int main() {
    SparseVector<int> v1(5);
    v1.set(2, 1);
    v1.set(4, 2);
    cout << "First vector" << endl << v1 << endl;

    SparseVector<int> v2(5);
    v2.set(0, 4);
    v2.set(2, 8);
    v2.set(4, 5);
    cout << "Second vector" << endl << v2 << endl;

    cout << "Sum of vectors" << endl << v1 + v2 << endl;
    cout << "First vector + 10" << endl << v1 + 10 << endl;
    cout << "Second vector * 2" << endl << v2 * 2 << endl;
    cout << "Dot product" << endl << v1.dot(v2) << endl;
    cout << "Second vector ^ 2" << endl << (v2 ^ 2) << endl;

    SparseMatrix<int> m1(2, 3);
    m1.set(0, 0, 1);
    m1.set(1, 1, 2);
    m1.set(0, 1, 7);
    m1.set(1, 2, 4);
    cout << "First matrix" << endl << m1 << endl;

    SparseMatrix<int> m2(2, 3);
    m2.set(1, 0, 4);
    m2.set(1, 1, 11);
    cout << "Second matrix" << endl << m2 << endl;

    cout << "Sum of matrices" << endl << m1 + m2 << endl;
    cout << "First matrix + 5" << endl << m1 + 6 << endl;
    cout << "Second matrix * 8" << endl << m2 * 8 << endl;

    SparseMatrix<int> m1t = m1.transpose();
    cout << "First matrix transposed" << endl << m1t << endl;

    cout << "First matrix * First matrix transposed" << endl << m1 * m1t << endl;

    SparseMatrix<int> m3(3, 3);
    m3.set(0, 0, 1);
    m3.set(1, 0, 2);
    m3.set(1, 1, 2);
    m3.set(2, 0, 3);
    m3.set(2, 1, 4);
    m3.set(2, 2, 5);

    cout << "Square matrix" << endl << m3 << endl;
    cout << "Square matrix ^ 4" << endl << m3.power(3) << endl;

    return 0;
}