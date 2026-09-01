#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {

    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {

        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int x = 0; x < temp.size(); x++) {
        arr[low + x] = temp[x];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {

    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);

    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main() {

    vector<int> arr = {5, 2, 8, 1, 3};

    mergeSort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";

    return 0;
}