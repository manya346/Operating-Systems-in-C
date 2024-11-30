#include<stdio.h>
#include<stdbool.h>

int main(){
    int pno[] = {1, 2, 3, 4};
    int at[] = {0, 1, 2, 3};
    int bt[] = {4, 3, 5, 2};
    int n = sizeof(pno)/sizeof(pno[0]);
    int tat[n], ct[n], wt[n], rt[n], og_bt[n];
    bool completed[n];
    int completed_count = 0, curr_time = 0;
    for(int i=0; i<n; i++){
        og_bt[i] = bt[i];
        completed[i] = false;
    }
    int tq=2;
    while(completed_count<n){
        bool processed = false;
        for(int i=0; i<n; i++){
            if(at[i]<=curr_time && bt[i]>0){
                if(!completed[i]){
                    rt[i] = curr_time - at[i];
                    completed[i] = true;
                }
                if(bt[i]>tq){
                    curr_time+=tq;
                    bt[i]-=tq;
                }
                else{
                    curr_time+=bt[i];
                    bt[i] = 0;
                    ct[i] = curr_time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - og_bt[i];
                    completed_count++;
                }
                processed = true;
            }
        }
        if(!processed){
            curr_time++;
        }
    }
    printf("pno\tat\tbt\tct\ttat\twt\trt\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pno[i], at[i], og_bt[i], ct[i], tat[i], wt[i], rt[i]);
    }
}
