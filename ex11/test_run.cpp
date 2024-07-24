#include <iostream>
#include <cmath>
 
using namespace std;
 
const int MAXN = 105;
double a[MAXN][MAXN];
 
double determinant(int n) {
    double det = 1.0;
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(a[j][i]) > abs(a[pivot][i])) {
                pivot = j;
            }
        }
        if (pivot != i) {
            swap(a[i], a[pivot]);
            det *= -1;
        }
        if (a[i][i] == 0) {
            return 0;
        }
        det *= a[i][i];
        for (int j = i + 1; j < n; j++) {
            double factor = a[j][i] / a[i][i];
            for (int k = i + 1; k < n; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }
    return det;
}
 
int main() {
    int n = 4;
    double matrix[4][4] = {{8.0, 5.0, -2.0, 4.0}, {4.0, 2.5, 20.0, 4.0}, {8.0, 5.0, 1.0, 4.0}, {28.0, -4.0, 17.0, 1.0}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = matrix[i][j];
        }
    }
    double det = determinant(n);
    cout << "Determinant = " << det << endl;
    return 0;
}