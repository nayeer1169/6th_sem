#include <stdio.h>

struct Process {
    int id;
    int arrival;
    int burst;
};

void calculateTimes(struct Process processes[], int n, int turnaround[], int waiting[]) {
    int totalWaiting = 0;
    int totalTurnaround = 0;

    waiting[0] = 0;
    turnaround[0] = processes[0].burst;

    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + processes[i - 1].burst;
        turnaround[i] = waiting[i] + processes[i].burst;
        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];
    }

    printf("\nAverage Waiting Time: %d\n", totalWaiting / n);
    printf("Average Turnaround Time: %d\n", totalTurnaround / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    int turnaround[n], waiting[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrival);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst);
    }

    calculateTimes(processes, n, turnaround, waiting);

    return 0;
}
