#include <iostream>
using namespace std;
bool check(int *arr,int n){
    int c = 0;
    int k = n - 1;
    for(int i = 1;i<n;i++){
        if(arr[i-1]>arr[i]){
            c++;
        }
    }
    if(arr[k]>arr[0]){
        c++;
    }
    return c == 1;
}
int main(){
    int arr[] = {1,2,3,6,5};
    int ans = check(arr, 5);
    if (ans == 1) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}