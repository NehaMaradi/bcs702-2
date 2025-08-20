#include <stdio.h>
#include <time.h>
#include <omp.h>

int main() {
    int n, i;
    long long sum = 0;
    double start, end;  // Use omp_get_wtime() for better precision timing

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Start timer
    start = omp_get_wtime();

    // Parallel sum using reduction to avoid race conditions
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    // End timer
    end = omp_get_wtime();

    printf("Sum of elements: %lld\n", sum);
    printf("Execution time: %f seconds\n", end - start);

    return 0;
}
