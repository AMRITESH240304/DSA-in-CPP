#include <iostream>
using namespace std;
int move(int arr[],int n){
    int i = 0;
    for(int j=0;j<n;j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
    for(int k = 0;k<n;k++){
        cout<<arr[k]<<" ";
    }
}
int main(){
    int arr[] = {0,1,0,3,1,12};
    move(arr,6);                                                                           
    return 0;
}   