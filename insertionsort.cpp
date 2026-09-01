#include<iostream>
using namespace std;
void insertionsort(int arr[],int n){
 for (int i = 1; i <n; i++)
 {
     int key=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
 }
 for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
 }
 
}
int main(){
   int arr[5]={2,3,4,1,5};
   int n=sizeof(arr)/sizeof(arr[0]);
   insertionsort(arr,n);
}