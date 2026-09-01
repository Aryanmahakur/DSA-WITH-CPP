#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

int quickSelect(vector<int>& arr, int low, int high, int k) {

    if (low == high)
        return arr[low];

    int p = partition(arr, low, high);

    // k is 0-based index

    if (k == p)
        return arr[p];

    else if (k < p)
        return quickSelect(arr, low, p - 1, k);

    else
        return quickSelect(arr, p + 1, high, k);
}

int main() {

    vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};

    int k = 3;  // 4th smallest (0-based)

    cout << quickSelect(arr, 0, arr.size() - 1, k);

    return 0;
}