#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};

    int target = 30;

    cout << linearSearch(arr, target);

    return 0;
}