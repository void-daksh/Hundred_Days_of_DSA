/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.*/

#include <stdio.h>

int main() {
    int nums1[1000], nums2[1000];
    int n1, n2;
    int freq[1001] = {0};
    int result[1000];
    int k = 0;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &nums1[i]);
        freq[nums1[i]]++;  
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &nums2[i]);
        if (freq[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
