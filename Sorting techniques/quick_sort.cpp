#include<bits/stdc++.h>
using namespace std;

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low, j=high;

    do{
        do{ i++; }while(A[i]<= pivot);
        do{ j--; }while(A[j]>pivot);

        if(i<j)     swap(A[i], A[j]);
    }while(i<j);

    swap(A[low], A[j]);
    return j;
}

void Quick_sort(int A[], int low, int high)
{
    int j;
    if(low<high){
        j = partition(A,low,high);
        Quick_sort(A,low, j);
        Quick_sort(A, j+1, high);
    }
}

int main()
{
    ///int A[] = {11,13,7,11,16,9,24,5,10,3,INT32_MAX}, n=11, i;
    ///INT32_MAX is the highest integer which is infinity.
    int A[] = {11,13,7,11,16,9,24,5,10,3}, n=10, i;

    Quick_sort(A, 0, n);

    for(int i=0 ; i<10 ; i++)
        printf("%d ", A[i]);
    printf("\n");

}
