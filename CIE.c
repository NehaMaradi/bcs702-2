#include <stdio.h>
#include <time.h>

int main() {
    int n, i;
    long long sum = 0;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Start timer
    start = clock();

    // Example operation: sum of array elements
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    // End timer
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sum of elements: %lld\n", sum);
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}
