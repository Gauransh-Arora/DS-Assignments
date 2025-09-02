#include <iostream>
using namespace std;

void diagonalMatrix(int n) {
    int A[n];
    for (int i=0; i<n; i++) A[i] = 0;

    cout << "Enter elements of diagonal matrix:\n";
    for (int i=0; i<n; i++) {
        cout << "A["<<i+1<<"]["<<i+1<<"] = ";
        cin >> A[i];
    }

    cout << "\nMatrix:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) cout << A[i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

void triDiagonalMatrix(int n) {
    int size = 3*n - 2;
    int A[size];
    for (int i=0; i<size; i++) A[i]=0;

    cout << "Enter elements of tri-diagonal matrix:\n";
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (abs(i-j) <= 1) {
                int x;
                cout << "A["<<i<<"]["<<j<<"] = ";
                cin >> x;
                if (i-j==1) A[i-2] = x;                  
                else if (i==j) A[n-1+i-1] = x;          
                else if (i-j==-1) A[2*n-1+i-1] = x;      
            }
        }
    }

    cout << "\nMatrix:\n";
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i-j==1) cout << A[i-2] << " ";
            else if (i==j) cout << A[n-1+i-1] << " ";
            else if (i-j==-1) cout << A[2*n-1+i-1] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

void lowerTriangularMatrix(int n) {
    int size = n*(n+1)/2;
    int A[size];
    for (int i=0;i<size;i++) A[i]=0;

    cout << "Enter elements of lower triangular matrix:\n";
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            int x; cin >> x;
            int index = (i*(i-1))/2 + (j-1);
            A[index] = x;
        }
    }

    cout << "\nMatrix:\n";
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (j<=i) {
                int index = (i*(i-1))/2 + (j-1);
                cout << A[index] << " ";
            } else cout << 0 << " ";
        }
        cout << endl;
    }
}

void upperTriangularMatrix(int n) {
    int size = n*(n+1)/2;
    int A[size];
    for (int i=0;i<size;i++) A[i]=0;

    cout << "Enter elements of upper triangular matrix:\n";
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            int x; cin >> x;
            int index = (i-1)*n - (i-2)*(i-1)/2 + (j-i);
            A[index] = x;
        }
    }

    cout << "\nMatrix:\n";
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (j>=i) {
                int index = (i-1)*n - (i-2)*(i-1)/2 + (j-i);
                cout << A[index] << " ";
            } else cout << 0 << " ";
        }
        cout << endl;
    }
}

void symmetricMatrix(int n) {
    int size = n*(n+1)/2;
    int A[size];
    for (int i=0;i<size;i++) A[i]=0;

    cout << "Enter elements of symmetric matrix (lower triangle only):\n";
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            int x; cin >> x;
            int index = (i*(i-1))/2 + (j-1);
            A[index] = x;
        }
    }

    cout << "\nMatrix:\n";
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i>=j) {
                int index = (i*(i-1))/2 + (j-1);
                cout << A[index] << " ";
            } else {
                int index = (j*(j-1))/2 + (i-1);
                cout << A[index] << " ";
            }
        }
        cout << endl;
    }
}

// - Driver -
int main() {
    int n;
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    cout << "\n (a) Diagonal Matrix \n";
    diagonalMatrix(n);

    cout << "\n (b) Tri-Diagonal Matrix \n";
    triDiagonalMatrix(n);

    cout << "\n (c) Lower Triangular Matrix \n";
    lowerTriangularMatrix(n);

    cout << "\n (d) Upper Triangular Matrix \n";
    upperTriangularMatrix(n);

    cout << "\n (e) Symmetric Matrix \n";
    symmetricMatrix(n);

    return 0;
}
