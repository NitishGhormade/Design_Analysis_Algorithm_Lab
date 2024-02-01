#include<stdio.h>

int ls,rs,cs;

int cross_sum(int arr[],int sidx,int eidx){

}

int max_sum_subarr(int arr[],int sidx,int eidx){
    if(sidx == eidx){
        return
    }
    else{
        int mid = (sidx + eidx)/2;

        ls = max_sum_subarr(arr,sidx,mid);
        rs = max_sum_subarr(arr,mid + 1,eidx);


    }
}

void main(){
    int arr[] = {-2,4,6,-2,5,-1,2};

    int i;
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array Print: ");
    for(i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }

    int sum = max_sum_subarr(arr,0,n-1);
    printf("SUM: %d",sum);
}
