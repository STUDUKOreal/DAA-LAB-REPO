#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, temp;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], end[n];

    for (i = 0; i < n; i++) {
        printf("Enter start and finish time: ");
        scanf("%d %d", &start[i], &end[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (end[j] > end[j + 1]) {
                temp = end[j];
                end[j] = end[j + 1];
                end[j + 1] = temp;

                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }

    printf("Selected activities:\n");

    printf("Activity 1: (%d, %d)\n", start[0], end[0]);
    int last = 0;

    for (i = 1; i < n; i++) {
        if (start[i] >= end[last]) {
            printf("Activity %d: (%d, %d)\n",
                   i + 1, start[i], end[i]);
            last = i;
        }
    }

    return 0;
}