#include <iostream>
using namespace std;
int main(){
    int arr[10] = {5,8,3};
    cout<<"address of first memory block is -> "<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<"address of first memory block is -> "<<&arr[0]<<endl;
    cout<<*arr<<endl;
    cout<<"value a 1st index -> "<<*(arr+1)<<endl;
    cout<<*(arr) + 1<<endl;
    return 0;
}