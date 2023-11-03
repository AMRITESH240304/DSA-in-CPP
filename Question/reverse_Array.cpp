#include <iostream>
#include <vector>

using namespace std;

vector<int> reverse(vector<int> v,int K){
    int s = K;
    int e = v.size()-1;
    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}

void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    int key;
    cout<<"Enter the Index from which you want reverse "<<endl;
    cin>>key;
    vector<int> ans = reverse(arr,key); 

    cout<<"printing array"<<endl;
    print(ans);

    return 0;
}