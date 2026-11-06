
#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int r) {
    int temp[1000];
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[l + i] = temp[i];
}

void mergeSort(int a[], int l, int r) {
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}

int main() {
    int a[] = {40, 10, 30, 20, 50};
    int n = 5;

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
