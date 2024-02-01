#include<stdio.h>

int partiton(int arr[],int sidx,int eidx){
    int i = sidx - 1;
    int j;
    int pivot = arr[eidx];
    int temp;

    for(j = sidx;j <= eidx - 1;j++){
        if(arr[j] < pivot){
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = pivot;
    arr[eidx] = temp;
    return i + 1;
}

void quicksort(int arr[],int sidx,int eidx){
    if(sidx <= eidx){
        int pidx = partiton(arr,sidx,eidx);

        quicksort(arr,sidx,pidx - 1);
        quicksort(arr,pidx + 1,eidx);
    }
}

void main(){
    int i;
    int arr[] = {9,2,3,5,1,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted Array: ");
    for(i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }

    quicksort(arr,0,n-1);

    printf("\nSorted Array: ");
    for(i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }
}