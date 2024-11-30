#include <stdio.h>
#include<stdbool.h>

int main(){
    int pno[] = {1, 2, 3, 4, 5};
    int at[] = {0, 2, 4, 5, 10};
    int bt[] = {5, 2, 1, 3, 1};
    int n = sizeof(pno)/sizeof(pno[0]);
    int og_bt[n], rt[n], ct[n], tat[n], wt[n];
    bool completed[n];
    int completed_count=0, curr_time=0;
    for(int i=0; i<n; i++){
        og_bt[i] = bt[i];
        completed[i] = false;
    }
    while(completed_count<n){
        int shortest=-1;
        int min_bt = 1e9;
        for(int i=0; i<n; i++){
            if(at[i]<=curr_time && bt[i]>0 && bt[i]<min_bt){
                min_bt = bt[i];
                shortest = i;
            }
        }
        if(shortest==-1){
            curr_time++;
            continue;
        }
        if(!completed[shortest]){
            rt[shortest] = curr_time - at[shortest];
            completed[shortest] = true;
        }
        bt[shortest]--;
        curr_time++;
        if(bt[shortest]==0){
            completed_count++;
            ct[shortest] = curr_time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - og_bt[shortest];
        }
    }
    printf("pno\tat\tbt\tct\ttat\twt\trt\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pno[i], at[i], og_bt[i], ct[i], tat[i], wt[i], rt[i]);
    }
}
