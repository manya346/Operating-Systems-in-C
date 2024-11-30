#include<stdio.h>
#include<stdbool.h>

void sortByArrival(int arr[], int at[], int bt[], int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(at[j]>at[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
            }
        }
    }
}

int main(){
    int pno[] = {1,2,3,4,5};
    int at[] = {3, 3, 2, 0, 1};
    int bt[] = {2, 1, 8, 4, 5};
    int n = sizeof(pno)/sizeof(pno[0]);
    sortByArrival(pno,at,bt,n);
    int ct[n], tat[n], wt[n], rt[n];
    bool completed[n];
    int completed_count = 0, curr_time = 0;
    float totaltat = 0, totalwt=0, totalrt = 0;
    for(int i=0; i<n; i++){
        completed[i] = false;
    }
    
    while(completed_count<n){
        int shortest = -1;
        int min_bt = 1e9;
        for(int i=0; i<n; i++){
            if(at[i]<=curr_time && !completed[i] && bt[i]<min_bt){
                min_bt = bt[i];
                shortest = i;
            }
        }
        if(shortest!=-1){
            curr_time += bt[shortest];
            ct[shortest] = curr_time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            rt[shortest] = curr_time - at[shortest];
            completed[shortest] = true;
            completed_count++;
            totaltat+=tat[shortest];
            totalwt+=wt[shortest];
            totalrt+=rt[shortest];
        }
        else{
            curr_time++;
        }
    }
    printf("pno\tat\tbt\tct\ttat\twt\trt\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pno[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }    
}
