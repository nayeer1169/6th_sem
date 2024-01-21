#include <stdio.h>

struct process{
    int pid;
    int at;
    int bt;
    int rt;
};

void calculate(struct process example[], int num, int quantum){
    int time = 0;
    int rem = num;

    while(rem>0){
        for(int i=0;i<num;i++){
            if(example[i].rt>0){
                int exe;
                if(example[i].rt < quantum){exe = example[i].rt;}
                else{exe = quantum;}

                example[i].rt -= exe;
                time += exe;

                printf("\nTime: %d, Process: %d, Executed: %d units", time, example[i].pid, exe);

                if(example[i].rt == 0){rem--;}

            }
        }
    }
}

int main(){
    int prNum;
    printf("Enter number of processes: ");
    scanf("%d", &prNum);
    
    struct process example[prNum];
    for(int i=0; i<prNum; i++){
        printf("Enter Arrival Time and Burst Time of process %d: ", i+1);
        scanf("%d %d", &example[i].at, &example[i].bt);
        example[i].pid = i+1;
        example[i].rt = example[i].bt;
    }

    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    calculate(example, prNum, quantum);

    return 0;
}