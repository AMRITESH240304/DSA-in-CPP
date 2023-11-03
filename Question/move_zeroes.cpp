#include <iostream>
using namespace std;
int move(int size,int arr[]){
    int i=0;
    for(int j = 0;j < size;j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
}
int main(){
    int arr[] = {0,1,0,2,3};
    move(5,arr);
    return 0;
}   