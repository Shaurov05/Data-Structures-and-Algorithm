#include<bits/stdc++.h>
using namespace std;

void create_max_heap(int *arr, int n)
{
    int temp = arr[n];
    int i=n;
    while(i>1 && temp>arr[i/2]){
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

void display(int arr[], int n){
    for(int i=1; i<=n ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10] = {0,10,20,30,25,5,40,35};
    for(int i=2; i<=7 ; i++){
        create_max_heap(arr, i);
    }
    display(arr, 7);
}

