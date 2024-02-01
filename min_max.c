#include<stdio.h>

int min = 0,max = 0;
void min_max(int arr[],int sidx,int eidx){
    if(sidx == eidx){
        min = arr[sidx];
        max = arr[sidx];
    }
    else if(sidx + 1 == eidx){
        if(arr[sidx] > arr[eidx]){
            min = arr[eidx];
            max = arr[sidx];
        }
        else{
            min = arr[sidx];
            max = arr[eidx];
        }
    }
    else{
        int mid = (sidx + eidx)/2;
        min_max(arr,sidx,mid);

        int tmpmin = min;
        int tmpmax = max;

        min_max(arr,mid + 1,eidx);

        if(min < tmpmin) min = min;
        else min = tmpmin;

        if(max > tmpmax) max = max;
        else max = tmpmax;
    }
}

void main(){
    int arr[] = {9,2,3,5,1,6,7,8};

    int i;
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array Print: ");
    for(i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }

    min_max(arr,0,n-1);
    printf("\nMIN: %d",min);
    printf("\nMAX: %d",max);
}
