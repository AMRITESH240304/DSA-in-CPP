#include <iostream>
using namespace std;

int merge(int *arr, int s, int mid, int e) {
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[k++];
    }

    int inversionCount = 0;
    int index1 = 0;
    int index2 = 0;
    k = s;

    while (index1 < len1 && index2 < len2) {
        if (first[index1] <= second[index2]) {
            arr[k++] = first[index1++];
        } else {
            arr[k++] = second[index2++];
            inversionCount += len1 - index1;
        }
    }

    while (index1 < len1) {
        arr[k++] = first[index1++];
    }

    while (index2 < len2) {
        arr[k++] = second[index2++];
    }

    delete[] first;
    delete[] second;

    return inversionCount;
}

int mergeSort(int *arr, int s, int e) {
    if (s >= e) {
        return 0;
    }
    int mid = (s + e) / 2;
    int leftInversions = mergeSort(arr, s, mid);
    int rightInversions = mergeSort(arr, mid + 1, e);
    int mergeInversions = merge(arr, s, mid, e);

    return leftInversions + rightInversions + mergeInversions;
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;
    int inversionCount = mergeSort(arr, 0, n - 1);

    cout << "Inversion Count: " << inversionCount << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
