#include<vector>
#include<matrix.h>
#include <iostream>

using namespace std;

int main() {
    vector<vector<float>> A = {{1,2,3},{4,5,6}};
    vector<vector<float>> B = {{1,1},{2,2},{3,3}};

    // matmul
    auto C = matmul(A, B);
    cout << "matrix A:" << endl;
    printMatrix(A);
    cout << endl << "matrix B:" << endl;
    printMatrix(B);
    cout << endl << "A x B:" << endl;
    printMatrix(C);

    // transpose
    auto T = transpose(A);
    cout << endl << "transpose of A:" << endl;
    printMatrix(T);

    // getCofactor
    vector<vector<float>> D = {{1,2,1},{5,1,2},{3,1,3}};
    cout << endl << "matrix D:" << endl;
    printMatrix(D);
    cout << endl << "getCofactor(D, 1, 1):" << endl;
    auto cofactor = getCofactor(D, 1, 1);
    printMatrix(cofactor);

    auto det = determinant(D);
    cout << endl << "determinant of matrix D: " << det << endl;

    // disjoint
    //vector<vector<float>> E = {{3,1,1},{1,3,-1},{2,4,1}};
    auto adj = adjoint(D);
    cout << endl << "adjoint matrix of matrix D:" << endl;
    printMatrix(adj);

    // inverse
    vector<vector<float>> I = {{1,2},{3,4}};
    cout << endl << "matrix I:" << endl;
    printMatrix(I);
    auto i = inverse(I);
    cout << endl << "inverse of matrix I:" << endl;
    printMatrix(i);

    return 0;
}
