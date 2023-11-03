#include <iostream>
using namespace std;
int peak(int *arr,int s,int e){
    if(s>e){
        return s;
    }
    int mid = (s+e)/2;
    if(arr[mid]<arr[mid+1]){
        peak(arr,mid + 2,e);
    }
    else{
        peak(arr,s,mid);
    }
}
int main(){
    int arr[] = {0,2,1,0};
    int s = 0,e = 4;
    int ans = peak(arr,s,e);
    cout<<"peak element :"<<ans<<endl;
    return 0;
}