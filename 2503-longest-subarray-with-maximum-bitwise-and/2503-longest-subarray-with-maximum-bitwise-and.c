int longestSubarray(int* nums, int numsSize) {
    int max = 0;
    int count = 0;
    int tracked = 0;
    for (int i = 0; i < numsSize; i++) {
        if(i > 0){
            if(nums[i]!=nums[i-1]){
                tracked = 0;
            }
            if(nums[i] == max){
                tracked++;
            }
        }
        if (nums[i] > max) {
            max = nums[i];
            count = 0;
            tracked++;
        }
        if(tracked > count) count = tracked;
    }
    // printf("%d\n", max);
    return count;
}