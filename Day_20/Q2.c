/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.*/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int** threeSum(int* nums, int n, int* rs, int** rcs) {
    qsort(nums, n, sizeof(int), cmp);
    
    int cap = 100;
    int** res = malloc(cap * sizeof(int*));
    *rcs = malloc(cap * sizeof(int));
    *rs = 0;

    for(int i = 0; i < n - 2; i++) {
        if(i && nums[i] == nums[i - 1]) continue;
        
        int l = i + 1, r = n - 1;
        
        while(l < r) {
            int s = nums[i] + nums[l] + nums[r];
            
            if(s == 0) {
                res[*rs] = malloc(3 * sizeof(int));
                res[*rs][0] = nums[i];
                res[*rs][1] = nums[l];
                res[*rs][2] = nums[r];
                
                (*rcs)[(*rs)++] = 3;
                
                while(l < r && nums[l] == nums[l + 1]) l++;
                while(l < r && nums[r] == nums[r - 1]) r--;
                
                l++; r--;
            }
            else if(s < 0) l++;
            else r--;
        }
    }
    
    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[100];
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int rs;
    int* rcs;

    int** res = threeSum(nums, n, &rs, &rcs);

    for(int i = 0; i < rs; i++) {
        for(int j = 0; j < 3; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }

    return 0;
}