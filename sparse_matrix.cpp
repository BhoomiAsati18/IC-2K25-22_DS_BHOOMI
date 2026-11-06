
#include <iostream>
using namespace std;

int main() {
    int a[10][10], triplet[101][3];
    int r, c, k = 1;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix:\n";

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];

            if (a[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = a[i][j];
                k++;
            }
        }
    }

    triplet[0][0] = r;
    triplet[0][1] = c;
    triplet[0][2] = k - 1;

    cout << "\nTriplet Representation:\n";
    cout << "Row Column Value\n";

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 3; j++)
            cout << triplet[i][j] << " ";

        cout << endl;
    }

    return 0;
}
