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

int delete_heap(int arr[], int heap_size)
{
    int temp,x,i,j;
    int value = arr[1];
    x = arr[heap_size];
    arr[1] = arr[heap_size];
    arr[heap_size] = value;
    i=1, j=2*i;

    while( j< heap_size-1 ){
        if(arr[j+1]>arr[j])
            j= j+1;
        if(arr[i] < arr[j]){
            swap(arr[i],arr[j]);
            i=j;
            j=2*j;
        }
        else
            break;
    }
    return value;
}

int main()
{
    int arr[10] = {0,10,20,30,25,5,40,35};
    for(int i=2; i<=7 ; i++){
        create_max_heap(arr, i);
    }
    printf("array : ");
    display(arr, 7);

    for(int i=7 ; i>0 ; i--){
        printf("Deleted value is : %d\n",delete_heap(arr, i));
    }
    printf("sorted array using heap sort : ");
    display(arr, 7);
}


