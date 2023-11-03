#include <iostream>
using namespace std;

void binary_search(int arr[][1000],int n,int m,int target){
    int r = 0;
    int c = m-1;
    while(r<n && c>=0){
        if(arr[r][c]==target){
            cout<<"Element found at "<<r<<" "<<c<<endl;
            return;
        }
        else if(arr[r][c]>target){
            c--;
        }
        else{
            r++;
        }
    }
    cout<<"Element not found"<<endl;
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int target;
    cin>>target;
    binary_search(arr,n,m,target);
    return 0;
}