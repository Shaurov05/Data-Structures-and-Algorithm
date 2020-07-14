#include<bits/stdc++.h>
using namespace std;

void Merge(int A[], int low, int mid, int high)
{
    int i=low,j=mid+1,k=low;
    int B[100];

    while(i<=mid && j<=high)
    {
        if(A[i]<A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(; i<=mid ;i++)
        B[k++] = A[i];
    for(; j<=high; j++)
        B[k++] = A[j];

    for(int i=low ; i<=high ; i++)
        A[i] = B[i];
}

void IMergeSort(int A[], int n)
{
    int p, low,high,mid,i;
    for(p=2; p<=n; p=p*2){
        for(i=0 ; i+p-1<=n ;i=i+p){
            low = i;
            high = i+p-1;
            mid = (low+high)/2;
            Merge(A, low, mid, high);
        }
    }
    if(p/2 <n)
        Merge(A,0,(p/2)-1,n-1);
}

void RMergeSort(int A[], int low, int high)
{
    if(low<high){
        int mid = (low+high)/2;
        RMergeSort(A,low,mid);
        RMergeSort(A,mid+1,high);
        Merge(A,low,mid, high);
    }
}

int main()
{
    int Arr2[] = {11,13,7,12,16,9,24,5,10,3};

    RMergeSort(Arr2, 0, 10);

    printf("Recursive Sort: ");
    for(int i=0 ; i<10 ; i++)
        printf("%d ", Arr2[i]);
    printf("\n");
}

