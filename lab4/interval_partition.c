#include <stdio.h>

int main() {
    int n, i, j, rooms = 0;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    int start[n], end[n], room[n];

    for (i = 0; i < n; i++) {
        printf("Enter start and end time: ");
        scanf("%d %d", &start[i], &end[i]);
    }

    for (i = 0; i < n; i++)
        room[i] = -1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < rooms; j++) {
            int available = 1;

            for (int k = 0; k < i; k++) {
                if (room[k] == j && start[i] < end[k]
                    && end[i] > start[k]) {
                    available = 0;
                    break;
                }
            }

            if (available) {
                room[i] = j;
                break;
            }
        }

        if (room[i] == -1)
            room[i] = rooms++;
    }

    for (i = 0; i < n; i++)
        printf("Interval %d: Room %d\n", i + 1, room[i] + 1);

    printf("Total rooms required: %d\n", rooms);

    return 0;
}