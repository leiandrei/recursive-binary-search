#include <stdio.h>

void sorted(int arr[], int size);
void print(int arr[], int size);
int binary_search(int arr[], int low, int upper, int target);

int main()
{
    int arr[] = {5, 6, 8, 4, 7, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    sorted(arr, size);

    int target;

    printf("Enter the search element: ");
    scanf("%d", &target);

    int result = binary_search(arr, 0, size - 1, target);

    if (result != -1) {
        printf("Element %d is found at index %d.\n", target, result);
    } else {
        printf("Element not found.\n");
    }
    print(arr, size);
    return 0;
}

void sorted(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int binary_search(int arr[], int low, int upper, int target)
{
    if (low > upper) {
        return -1;
    }

    int mid = (upper + low) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binary_search(arr, mid + 1, upper, target);
    } else {
        return binary_search(arr, low, mid - 1, target);
    }
}
