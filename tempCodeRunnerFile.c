#include <stdio.h>

int merge(int arr[], int aux[], int left, int mid, int right) {
    int i, j, k;
    int invCount = 0;

    i = left;
    j = mid;
    k = left;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        } else {
            aux[k++] = arr[j++];
            invCount += (mid - i);
        }
    }

    while (i <= mid - 1) {
        aux[k++] = arr[i++];
    }

    while (j <= right) {
        aux[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = aux[i];
    }

    return invCount;
}

int mergeSort(int arr[], int aux[], int left, int right) {
    int mid, invCount = 0;

    if (right > left) {
        mid = (left + right) / 2;

        invCount = mergeSort(arr, aux, left, mid);
        invCount += mergeSort(arr, aux, mid + 1, right);
        invCount += merge(arr, aux, left, mid + 1, right);
    }

    return invCount;
}

int countInversions(int arr[], int n) {
    int aux[n];
    return mergeSort(arr, aux, 0, n - 1);
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Number of inversions: %d\n", countInversions(arr, n));

    return 0;
}
