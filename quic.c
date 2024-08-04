
#include<stdio.h>
void quick_sort(int a[], int low, int high) {
    if (low < high) {
        int pivot;
        pivot = partition(a, low, high);
        quick_sort(a, low, pivot - 1);
        quick_sort(a, pivot + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low;
    int j = high;
    int temp;

    while (i < j) {
        while (i <= high && a[i] <= pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

int main() 
{
    int a[10], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    quick_sort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
