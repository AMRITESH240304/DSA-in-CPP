#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    // for decending order
    // for(int i = 0;i < n-1;i++){
    //     for(int j = 0;j < n-i-1;j++){
    //         if(arr[j]<arr[j+1]){
    //             swap(arr[j],arr[j+1]);
    //         }
    //     }
    // }
}

int main() {
    vector<int> arr = {10, 3, 6, 9};
    int n = arr.size();

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    bubbleSort(arr, n);

    cout << "\nSorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
