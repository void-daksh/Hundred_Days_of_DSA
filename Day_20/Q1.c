/*Problem: Given an array of integers, count the number of subarrays whose sum is 
equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array.
 For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: 
 [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3].
 Since there are 6 such subarrays, the output is 6.*/
#include <stdio.h>

int main() {
    int n, arr[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix[1000] = {0};
    int sum = 0, count = 0;

    prefix[500] = 1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        count += prefix[sum + 500];
        prefix[sum + 500]++;
    }

    printf("%d", count);

    return 0;
}