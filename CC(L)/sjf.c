#include <stdio.h>

struct Process {
    int id;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
};

void sjf(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival > processes[j + 1].arrival) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival <= currentTime) {
            processes[i].completion = currentTime + processes[i].burst;
            processes[i].turnaround = processes[i].completion - processes[i].arrival;
            processes[i].waiting = processes[i].turnaround - processes[i].burst;
            currentTime = processes[i].completion;
        } else {
            currentTime = processes[i].arrival;
            processes[i].completion = currentTime + processes[i].burst;
            processes[i].turnaround = processes[i].completion - processes[i].arrival;
            processes[i].waiting = processes[i].turnaround - processes[i].burst;
            currentTime = processes[i].completion;
        }
    }
}

void displayProcesses(struct Process processes[], int n) {
    printf("\nProcess\t Arrival\t Burst\t Completion\t Turnaround\t Waiting\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t %d\t\t %d\t %d\t\t %d\t\t %d\n", processes[i].id, processes[i].arrival,
               processes[i].burst, processes[i].completion, processes[i].turnaround, processes[i].waiting);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrival);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst);
    }

    sjf(processes, n);
    displayProcesses(processes, n);

    return 0;
}
