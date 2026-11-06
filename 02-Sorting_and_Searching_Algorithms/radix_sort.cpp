
#include <iostream>
using namespace std;

int getMax(int a[], int n) {
    int mx = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];

    return mx;
}

void countSort(int a[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[--count[digit]] = a[i];
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n) {
    int mx = getMax(a, n);

    for (int exp = 1; mx / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

int main() {
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;

    radixSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
