#include <iostream>
using namespace std;
bool binary(int *arr,int s,int e,int key){
    if(s>=e){
        return false;
    }

    int mid = (s+e)/2;

    if(arr[mid] == key){
        return true;
    }
    else if(arr[mid]>key){
        binary(arr,s,mid-1,key);
    }
    else{
        binary(arr,mid+1,e,key);
    }

}
int main(){
    int arr[] = {1,2,3,4,5,7};
    int e = 6;
    int s = 0;
    int key = 4;
    int ans = binary(arr,s,e,key);
    cout<<ans;
    return 0;
}