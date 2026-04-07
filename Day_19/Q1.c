/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, 
which is the closest to zero compared to other pairs.*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, arr[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int minSum = abs(arr[left] + arr[right]);
    int a = arr[left], b = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < minSum) {
            minSum = abs(sum);
            a = arr[left];
            b = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", a, b);

    return 0;
}