#include<stdio.h>

void merge(int arr[],int sidx,int mid,int eidx){
    int i,j,k;
    int ln = mid - sidx + 1,rn = eidx - mid;
    int larr[ln],rarr[rn];

    for(i = 0;i < ln;i++){
        larr[i] = arr[sidx + i];
    }

    for(j = 0;j < rn;j++){
        rarr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = sidx;
    while(i < ln && j < rn){
        if(larr[i] < rarr[j]){
            arr[k++] = larr[i++];
        }
        else{
            arr[k++] = rarr[j++];
        }
    }

    while(i < ln){
        arr[k++] = larr[i++];
    }

    while(j < rn){
        arr[k++] = rarr[j++];
    }

}

void mergesort(int arr[],int sidx,int eidx){
    if(sidx <= eidx){
        int mid = (sidx + eidx)/2;

        mergesort(arr,sidx,mid);
        mergesort(arr,mid+1,eidx);
        merge(arr,sidx,mid,eidx);
    }
}

int main(){
    int arr[] = {6,5,9,2,7,3,1};
    
    int i;
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted Array: ");
    for(i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }

    mergesort(arr,0,n-1);

    printf("\nSorted Array: ");
    for(i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}