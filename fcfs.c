#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], wt[n], ct[n];

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
    }

    wt[0] = 0;
    ct[0] = bt[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        ct[i] = ct[i - 1] + bt[i];
    }

    float avg_wt = 0, avg_tat = 0;

    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += ct[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nProcess\tBT\tAT\tWT\tCT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], at[i], wt[i], ct[i]);
    }

    printf("\nAverage waiting time = %f", avg_wt);
    printf("\nAverage turnaround time = %f", avg_tat);

    return 0;
}
