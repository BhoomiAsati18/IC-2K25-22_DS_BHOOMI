
#include <iostream>
using namespace std;

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int n = 5, key;

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    int found = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == key) {
            found = mid;
            break;
        }
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (found != -1)
        cout << "Found at index " << found;
    else
        cout << "Not found";

    return 0;
}
