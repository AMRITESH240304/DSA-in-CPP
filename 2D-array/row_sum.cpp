#include <iostream>
#include <limits>
using namespace std;

void print_sum_row_col(int arr[3][3],int row,int col){
    int maxi = INT8_MIN;
    cout<<"Printing the sum of row"<<endl;
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum += arr[i][j];
        }
        cout<<sum<<" ";
        if(sum>maxi){
            maxi = sum;
        }
    }
    cout<<"\nSum of max row: ";
    cout<<maxi;
    cout << "\nPrinting the sum of col" << endl;
    for (int j = 0; j < col; j++) {
        int sum = 0;
        for (int i = 0; i<row; i++) {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
}

bool check(int arr[3][3],int row,int col,int target){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j] == target){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int arr[3][3];
    cout<<"Enter the element of (3X3)"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }

    int target;
    cout<<"Enter the element to search: ";
    cin>>target;

    if(check(arr,3,3,target)){
        cout<<"Element Found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

    print_sum_row_col(arr,3,3);

    return 0;
}