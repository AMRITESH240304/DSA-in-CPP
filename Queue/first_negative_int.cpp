#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                
        deque<long long int> dq;
        vector<long long> ans;
        
        //process first window fo k size;
        
        for (int i=0;i<K;i++){
            if(A[i] < 0){
                dq.push_back(i);
            }
        }
        
        //store answer of first k sized window; 
        
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        } else{
            ans.push_back(0);
        }
        
        for(int i=K;i<N;i++){
            //removal;
            
            if( ! dq.empty() && i - dq.front() >= K){
                dq.pop_front();
            }
            
            if(A[i] < 0){
                dq.push_back(i);
            }
            
            //ans store
            
            if(dq.size() > 0){
                ans.push_back(A[dq.front()]);
            } else {
                ans.push_back(0);
            }
        }
        
        return ans;
 }


int main(){
    long long int arr[] = {-8, 2, 3, -6, 10};
    long long int n = sizeof(arr)/sizeof(arr[0]);
    long long int k = 3;
    vector<long long> ans = printFirstNegativeInteger(arr,n,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;

}