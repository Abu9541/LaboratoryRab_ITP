#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int calculate(const vector<vector<int>>& matrix) {
    int sum = 0;
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> transposed(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}

int main() {
    ifstream in("a_task7.txt");
    ofstream ofs("b_task7.txt");
    ofstream out("c_task7.txt");

    int k, n;
    in >> k >> n;

    for (int mInd = 0; mInd < k; ++mInd) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                in >> matrix[i][j];
            }
        }
        int diagonalSum = calculate(matrix);
        if (diagonalSum % 2 != 0) {
            ofs << "Матрица " << mInd + 1 << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    ofs << matrix[i][j] << " ";
                }
                ofs << endl;
            }
            matrix = transpose(matrix);
            ofs << "Матрица " << mInd + 1 << " Транспонированная:" << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    ofs << matrix[i][j] << " ";
                }
                ofs << endl;
            }
        }
        out << "Матрица " << mInd + 1 << ":" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                out << matrix[i][j] << " ";
            }
            out << endl;
        }
    }
    in.close();
    ofs.close();
    out.close();
    cout << "Успешно." << endl;
    return 0;
}