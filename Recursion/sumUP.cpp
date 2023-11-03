#include <iostream>
using namespace std;
int sum(int *arr,int size){
    if(size == 0){
        return 0;
    }
    int get = arr[0] + sum(arr + 1, size - 1);
    // cout<<get<<endl;
    return get;
}
int main(){
    int arr[] = {1,2,3,4,5};
    int size = 5;
    int get = sum(arr,size);
    cout<<get<<endl;
    return 0;
}

