#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    int start;
    int finish;
    int weight;
};

// Function to compare jobs by finish time
int jobCompare(const void* a, const void* b) {
    return (((struct Job*)a)->finish - ((struct Job*)b)->finish);
}

// Returns the latest job that doesn't conflict with the current job
int latestNonConflict(struct Job jobs[], int i) {
    int l = 0;
    int r = i - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (jobs[m].finish <= jobs[i].start) {
            if (jobs[m + 1].finish <= jobs[i].start)
                l = m + 1;
            else
                return m;
        }
        else
            r = m - 1;
    }
    return -1;
}

// Returns the maximum weight that can be earned by scheduling jobs
int weightedIntervalScheduling(struct Job jobs[], int n) {
    int i, j, maxWeight;
    
    // Sort jobs by finish time
    qsort(jobs, n, sizeof(struct Job), jobCompare);
    
    // Initialize table
    int table[n];
    table[0] = jobs[0].weight;
    
    // Fill table in bottom-up manner
    for (i = 1; i < n; i++) {
        int inclWeight = jobs[i].weight;
        int l = latestNonConflict(jobs, i);
        if (l != -1)
            inclWeight += table[l];
        table[i] = (inclWeight > table[i - 1]) ? inclWeight : table[i - 1];
    }
    
    // Return maximum weight
    maxWeight = table[n - 1];
    return maxWeight;
}

int main() {
    struct Job jobs[] = {{1, 2, 50}, {3, 5, 20}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    printf("Maximum weight that can be earned is %d\n", weightedIntervalScheduling(jobs, n));
    return 0;
}
