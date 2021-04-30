#include <vector>
#include <iostream>

using namespace std;

void printMatrix(vector<vector<float>> v) {
    for (int i = 0; i < v.size(); i++) {       
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }            
        cout << endl;
    }
}

vector<vector<float>> matmul(vector<vector<float>> A, vector<vector<float>>B)
{
    int row = A.size();
    int col = B[0].size();
    vector<vector<float>> R(row, vector<float>(col));
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            float temp = 0.;
            for (int k = 0; k < A[0].size(); k++){
                temp += A[i][k] * B[k][j];
            }
            R[i][j] = temp;
        }
    }
    return R;
}

vector<vector<float>> transpose(vector<vector<float>> A) {
    int row = A.size();
    int col = A[0].size();
    vector<vector<float>> T(col, vector<float>(row));
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            T[j][i] = A[i][j];
        }
    }
    return T;
}

// Function to get cofactor of A[p][q]
vector<vector<float>> getCofactor(vector<vector<float>> A, int p, int q) {
    vector<vector<float>> temp;
    for (int i = 0; i < A.size(); i++) {
        if (i != p) {
            vector<float> t;
            for (int j = 0; j < A.size(); j++) {
                if (j != q) {
                    t.emplace_back(A[i][j]);
                }
            }
            temp.emplace_back(t);
            t.clear();
        }
    }
    return temp;
}

// Recursive function for finding determinant of matrix
float determinant(vector<vector<float>> A) {
    int D = 0;
    if (A.size() == 1)
        return A[0][0];
    int sign = 1;
    for (int i = 0; i < A.size(); i++) {
        // Getting Cofactor of A[0][i]
        auto temp = getCofactor(A, 0, i);
        D += sign * A[0][i] * determinant(temp);
        // terms are to be added with alternate sign
        sign = -sign;
    }
    return D;
}

vector<vector<float>> adjoint(vector<vector<float>> A) {
    auto row = A.size();
    auto col = A[0].size();
    vector<vector<float>> adj(row, vector<float>(col));
    if (A.size() == 1) {
        adj[0][0] = 1;
        return adj;
    }

    int sign = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            auto temp = getCofactor(A, i, j);
            // sign of adj[i][j] is positive if sum of row and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;
            // Interchanging rows and colunms to get the transpose of the cofactor matrix
            adj[j][i] = (sign)*(determinant(temp));
        }
    }
    return adj;
}

// Function to calculate and store inverse, returns false if matrix is singular
vector<vector<float>> inverse(vector<vector<float>> A) {
    auto det = determinant(A);
    auto row = A.size();
    auto col = A[0].size();
    vector<vector<float>> inv(row, vector<float>(col));
    if (det == 0) 
        cout << "Singular matrix, can't find its inverse";
    auto adj = adjoint(A);
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            inv[i][j] = adj[i][j]/det;
        }
    }
    return inv;
}
