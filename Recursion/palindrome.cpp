#include <iostream>
using namespace std;

bool check(string str,int i,int j){
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
        return check(str,i+1,j-1);
    }
}

int main(){
    string name = "madam";

    bool ispalindrome = check(name,0,name.length()-1);

    if(ispalindrome){
        cout<<"correct"<<endl;
    }
    else{
        cout<<"not correct"<<endl;
    }
    return 0;
}