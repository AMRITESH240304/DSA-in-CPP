// #include <iostream>
// using namespace std;
// int fib(int n){
//     if(n<=1){
//         return 1;
//     }
//     int ans = fib(n-1) + fib(n-2);
//     return ans;
    
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<fib(n);
//    return 0;
// }

#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << fib(i) << " ";
    }
    
    return 0;
}

