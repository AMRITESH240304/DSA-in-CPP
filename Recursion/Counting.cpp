#include <iostream>
using namespace std;
int print(int n){
    if(n==0){
        return 1;
    }
    cout<<n<<endl;
    print(n-1);
}
int main(){
    print(5);
    return 0;
}