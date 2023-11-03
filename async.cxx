#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int **arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int target;
    cin>>target;
    int r = 0;
    int c = m-1;
    while(r<n && c>=0){
        if(arr[r][c]==target){
            cout<<"Element found at "<<r<<" "<<c<<endl;
            return 0;
        }
        else if(arr[r][c]>target){
            c--;
        }
        else{
            r++;
        }
    }
    cout<<"Element not found"<<endl;
    return 0;
}