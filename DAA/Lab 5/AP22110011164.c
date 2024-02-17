// AP22110011164

#include <stdio.h>
#include <limits.h>

int maximum(int x, int y) {
    return (x > y) ? x : y;
}

int minimum(int x, int y) {
    return (x < y) ? x : y;
}

int max_crossing_subarray(int array[], int low, int mid, int high) {
    int left_max_sum = INT_MIN;
    int sum = 0;
    int max_index = mid;

    for (int i = mid; i >= low; i--) {
        sum += array[i];
        if (sum > left_max_sum) {
            left_max_sum = sum;
            max_index = i;
        }
    }

    int right_max_sum = INT_MIN;
    sum = 0;
    int min_index = mid + 1;

    for (int i = mid + 1; i <= high; i++) {
        sum += array[i];
        if (sum > right_max_sum) {
            right_max_sum = sum;
            min_index = i;
        }
    }

    return maximum(left_max_sum + right_max_sum, maximum(left_max_sum, right_max_sum));
}

int max_subarray_sum(int array[], int low, int high) {
    if (low == high) {
        return array[low];
    }

    int mid = (low + high) / 2;

    int left_max_sum = max_subarray_sum(array, low, mid);
    int right_max_sum = max_subarray_sum(array, mid + 1, high);
    int cross_max_sum = max_crossing_subarray(array, low, mid, high);

    return maximum(left_max_sum, maximum(right_max_sum, cross_max_sum));
}

int main() {
    int n;
    scanf("%d", &n);

    int array[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int max_sum = max_subarray_sum(array, 0, n - 1);
    printf("%d\n", max_sum);

    return 0;
}
