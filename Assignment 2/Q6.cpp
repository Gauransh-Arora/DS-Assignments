#include <iostream>
using namespace std;

#define MAX 100

void display(int a[MAX][3]) {
    int n = a[0][2];
    cout << "Row Col Val\n";
    for (int i = 0; i <= n; i++) {
        cout << a[i][0] << "   " << a[i][1] << "   " << a[i][2] << "\n";
    }
}

void transpose(int a[MAX][3], int b[MAX][3]) {
    int n = a[0][2];
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = n;

    int k = 1;
    for (int c = 0; c < a[0][1]; c++) {
        for (int i = 1; i <= n; i++) {
            if (a[i][1] == c) {
                b[k][0] = a[i][1];
                b[k][1] = a[i][0];
                b[k][2] = a[i][2];
                k++;
            }
        }
    }
}

void add(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible\n";
        return;
    }

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    int i=1, j=1, k=1;
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || 
           (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2];
            i++; k++;
        }
        else if (b[j][0] < a[i][0] || 
                (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            c[k][0] = b[j][0]; c[k][1] = b[j][1]; c[k][2] = b[j][2];
            j++; k++;
        }
        else {
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }
    while (i <= a[0][2]) { c[k][0]=a[i][0]; c[k][1]=a[i][1]; c[k][2]=a[i][2]; i++; k++; }
    while (j <= b[0][2]) { c[k][0]=b[j][0]; c[k][1]=b[j][1]; c[k][2]=b[j][2]; j++; k++; }

    c[0][2] = k-1;
}

void multiply(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible\n";
        return;
    }

    int bt[MAX][3];
    transpose(b, bt);

    c[0][0] = a[0][0];
    c[0][1] = b[0][1];
    c[0][2] = 0;
    int k = 1;

    for (int i = 1; i <= a[0][2]; ) {
        int row = a[i][0];

        int rowElems[MAX][3], rCount=0;
        while (i <= a[0][2] && a[i][0] == row) {
            rowElems[rCount][0] = a[i][0];
            rowElems[rCount][1] = a[i][1];
            rowElems[rCount][2] = a[i][2];
            rCount++; i++;
        }

        for (int j = 1; j <= bt[0][2]; ) {
            int col = bt[j][0];

            int colElems[MAX][3], cCount=0;
            while (j <= bt[0][2] && bt[j][0] == col) {
                colElems[cCount][0] = bt[j][0];
                colElems[cCount][1] = bt[j][1];
                colElems[cCount][2] = bt[j][2];
                cCount++; j++;
            }

            int sum = 0;
            for (int p = 0; p < rCount; p++) {
                for (int q = 0; q < cCount; q++) {
                    if (rowElems[p][1] == colElems[q][1]) {
                        sum += rowElems[p][2] * colElems[q][2];
                    }
                }
            }

            if (sum != 0) {
                c[k][0] = row;
                c[k][1] = col;
                c[k][2] = sum;
                k++;
            }
        }
    }
    c[0][2] = k-1;
}

int main() {
    int A[MAX][3] = {
        {3,3,3},
        {0,2,5},
        {1,0,3},
        {2,1,7}
    };

    int B[MAX][3] = {
        {3,3,3},
        {0,0,2},
        {1,0,1},
        {2,2,4}
    };

    cout << "Matrix A:\n"; display(A);
    cout << "\nMatrix B:\n"; display(B);

    int T[MAX][3], C[MAX][3], M[MAX][3];

    transpose(A, T);
    cout << "\nTranspose of A:\n"; display(T);

    add(A, B, C);
    cout << "\nA + B:\n"; display(C);

    multiply(A, B, M);
    cout << "\nA * B:\n"; display(M);

    return 0;
}
