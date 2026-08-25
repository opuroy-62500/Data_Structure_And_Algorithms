#include<iostream>
#include<climits>
using namespace std;

void MatrixChainMultiplication(int p[], int n) {
    int m[n][n];
    int s[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications is " << m[1][n - 1] << endl;
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int p[n + 1];
    cout << "Enter the dimensions of matrices: ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    MatrixChainMultiplication(p, n + 1);

    return 0;
}
