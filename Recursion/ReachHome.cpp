#include <iostream>
using namespace std;
int reachHome(int man_walk,int home){
    cout<<"Walk "<<man_walk<<"home "<<home<<endl;
    if(man_walk == home){
        cout<<"reached home"<<endl;
        return 1;
    }
    man_walk++;
    reachHome(man_walk,home);
}
int main(){
    int man_walk = 0;
    int home = 10;
    reachHome(man_walk,home);
    return 0;
}