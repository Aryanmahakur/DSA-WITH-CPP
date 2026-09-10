#include <iostream>
#include <vector>
using namespace std;

void heapifyDown(vector<int>& arr, int n, int i) {

    while (true) {

        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest == i)
            break;

        swap(arr[i], arr[largest]);

        i = largest;
    }
}

void heapSort(vector<int>& arr) {

    int n = arr.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(arr, n, i);
    }

    // Sortinga
    for (int i = n - 1; i > 0; i--) {
d
        // Move maximum to the ends
        swap(arr[0], arr[i]);

        // Heapify remaining heap
        heapifyDown(arr, i, 0);
    }
}

int main() {

    vector<int> arr = {4, 10, 3, 5, 1};

    heapSort(arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}