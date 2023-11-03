// to find any largest number of array appy quicksort 
#include<stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int third(int *arr,int size,int n){
    if(size < n){
        return 0;
    }
    else{
        return arr[size-n];
    }
}
int main(){
    int arr[] = {19, -10, 20, 14, 2, 16, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, size, sizeof(int), compare);
    int n;
    printf("Which largest element you want to find: ");
    scanf("%d",&n);

    int ans = third(arr,size,n);
    printf("%d",ans);
    return 0;
}