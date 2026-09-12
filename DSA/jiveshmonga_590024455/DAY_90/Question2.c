#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    return x[0] - y[0];
}

int videoStitching(int** clips, int clipsSize, int* clipsColSize, int time) {
    qsort(clips, clipsSize, sizeof(int *), compare);

    int current = 0;
    int count = 0;
    int i = 0;

    while (current < time) {
        int farthest = current;

        while (i < clipsSize && clips[i][0] <= current) {
            if (clips[i][1] > farthest)
                farthest = clips[i][1];

            i++;
        }

        if (farthest == current)
            return -1;

        current = farthest;
        count++;
    }

    return count;
}