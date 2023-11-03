#include <iostream>
using namespace std;
int firstOcc(int *arr,int key,int s,int e,int ans){
    if(s>=e){
        return ans;
    }
    int mid =(s+e)/2;
    if(arr[mid] == key){
        ans = mid;
        // e = mid - 1;
        firstOcc(arr,key,s,mid-1,ans);
    }
    else if(arr[mid]<key){
        firstOcc(arr,key,mid+1,e,ans);
    }
    else{
        firstOcc(arr,key,s,mid-1,ans);
    }
}
int lastOcc(int *arr,int key,int s,int e,int ans){
    if(s>=e){
        return ans;
    }
    int mid =(s+e)/2;
    if(arr[mid] == key){
        ans = mid;
        // s = mid + 1;
        lastOcc(arr,key,mid+1,e,ans);
    }
    else if(arr[mid]<key){
        lastOcc(arr,key,mid+1,e,ans);
    }
    else{
        lastOcc(arr,key,s,mid-1,ans);
    }
}
int main(){
    int arr[11] = {1,2,2,3,3,3,3,3,3,3,5};
    int size = 11;
    int key = 3;
    int s = 0, e = size-1;
    int ans = -1;
    int first = firstOcc(arr,key,s,e,ans);

    int last = lastOcc(arr,key,s,e,ans);
    cout<<"first occerence: "<<first<<endl;
    cout<<"last occerence: "<<last<<endl;
    return 0;
}