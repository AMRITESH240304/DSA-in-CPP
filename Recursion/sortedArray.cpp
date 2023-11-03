#include <iostream>
using namespace std;
bool is_sorted(int *arr,int size){
    if(size == 0 || size == 1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool remain = is_sorted(arr+1,size-1);
        return remain;
    }
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    bool ans = is_sorted(arr,size);
    if(ans){
        cout<<"array is sorted "<<endl;
    }
    else{
        cout<<"array is not sorted"<<endl;
    }
   return 0;
}