#include<stdio.h>
#include<stdlib.h>

void sortByArrival(int arr[], int at[], int bt[], int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(at[j]>at[j+1]){
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int pno[] = {1,2,3,4,5};
    int at[] = {3, 3, 2, 0, 1};
    int bt[] = {2, 1, 8, 4, 5};
    int n = sizeof(pno) / sizeof(pno[0]);
    sortByArrival(pno, at, bt, n);
    int ct[n], tat[n], wt[n], rt[n];
    float totalct=0, totaltat=0, totalwt=0, totalrt=0;
    for(int i=0; i<n; i++){
        if(i==0){
            ct[i] = at[i]+bt[i];
            rt[i] = ct[i]-bt[i];
        }
        else{
            if(at[i]>ct[i-1]){
                ct[i] = at[i] + bt[i];
                rt[i] = ct[i] - bt[i];
            }
            else{
                ct[i] = ct[i-1] + bt[i];
                rt[i] = ct[i-1];
            }
        }
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] -bt[i];
        totaltat+=tat[i];
        totalwt+=wt[i];
        totalrt+=rt[i];
    }
    printf("pno\tat\tbt\tct\ttat\twt\trt\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pno[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }
}
