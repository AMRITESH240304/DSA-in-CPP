#include <iostream>
using namespace std;
int peak(int arr[],int n){
    int s = 0,e = n-1;
    int mid = (s+e)/2;
    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s = mid + 2;
        }
        else{
            e = mid;
        }
        mid = (s+e)/2;
    }   
    return s;
}
int main(){
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The peak element inside the given array"<<endl;
    cout<<peak(arr,n);
    return 0;
}