#include <iostream>
#include <vector>
using namespace std;
void move(int n,int arr[],int key){
    /*yaha pe vector pe n isiliye hai 
    kyuki khali vector ke andar ham operation 
    nhi perform kar sakte */
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        temp[(i+key)%n] = arr[i];
    }
    for(int i:temp){
        cout<<i;
    }
}
int main(){
    int arr[] = {1,2,3,4,5};
    int key;
    cin>>key;
    move(5,arr,key);
    return 0;
}