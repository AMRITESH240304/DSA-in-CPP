#include <iostream>
using namespace std;
int main(){
    int n = 5;

    cout<<"Address of n -> "<<&n<<endl;

    int *ptr = &n;

    cout<<"Address of ptr -> "<<ptr<<endl;
    cout<<"Value of ptr -> "<<*ptr<<endl;

    cout<<"size of num -> "<<sizeof(n)<<endl;
    /* in my case i am getting 4 bytes for ptr 
       but it depend on machine to machine 
       in most of the case the poiter would 
       be -> (8 bytes)*/
       
    cout<<"size of pointer -> "<<sizeof(ptr)<<endl;


    int i = 4;
    int a = i;

    cout<<"a before -> "<<i<<endl;
    a++;
    cout<<"a after -> "<<i<<endl;

    int *p = &i;
    cout<<"p before -> "<<i<<endl;
    (*p)++;
    cout<<"p after -> "<<i<<endl;

    // int num = 10;

    // int *ptr = &num;
    



    return 0;
}