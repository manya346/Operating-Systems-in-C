#include<stdio.h>
#include<stdbool.h>

int main(){
    int pno[] = {1, 2, 3, 4};
    int at[] = {0, 1, 2, 3};
    int bt[] = {4, 3, 5, 2};
    int priority[] = {2, 1, 0 ,3};
    int n = sizeof(pno)/sizeof(pno[0]);
    int ct[n], tat[n], wt[n], rt[n], og_bt[n];
    bool completed[n];
    int curr_time = 0, completed_count = 0;
    for(int i=0; i<n; i++){
        og_bt[i] = bt[i];
        completed[i] = false;
    }
    while(completed_count<n){
        int highest_priority = 1e9;
        int selected_process = -1;
        for(int i=0; i<n; i++){
            if(at[i]<=curr_time && bt[i]>0 && priority[i]<highest_priority){
                highest_priority = priority[i];
                selected_process = i;
            }
        }
        if(selected_process==-1){
            curr_time++;
            continue;
        }
        if(!completed[selected_process]){
            rt[selected_process] = curr_time - at[selected_process];
            completed[selected_process] = true;
        }
        bt[selected_process]--;
        curr_time++;
        if(bt[selected_process]==0){
            ct[selected_process] = curr_time;
            tat[selected_process] = ct[selected_process] - at[selected_process];
            wt[selected_process] = tat[selected_process] - og_bt[selected_process];
            completed_count++;
        }
    }
    printf("pno\tat\tbt\tprior\tct\ttat\twt\trt\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\t%d\n", pno[i], at[i], og_bt[i], priority[i], ct[i], tat[i], wt[i], rt[i]);
    }
}
