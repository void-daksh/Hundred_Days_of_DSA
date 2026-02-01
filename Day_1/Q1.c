#include <stdio.h>

int main() {
    int n, pos, x;
    int arr[100];
    printf("Enter Size of Array \n");
    scanf("%d", &n);
    printf("Enter Elements of Array With Space \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter Position \n");
    scanf("%d", &pos);
    printf("Enter Element to Insert \n");
    scanf("%d", &x);
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}