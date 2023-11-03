#include <iostream>
using namespace std;
bool linear_Search(int *arr,int size,int key){
    if(size == 0){
        return false;
    }
    if(arr[0] == key){
        return true;
    }
    else{
        bool remaining = linear_Search(arr+1,size-1,key);
    }
}
int main(){
    int arr[] = {1,2,3,4,5,60};
    int size = 6;
    int key = 6;
    bool ans = linear_Search(arr,size,key);
    if (ans != 0) {
        cout<<"Found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
   return 0;
}