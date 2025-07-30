class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = 0;
        int maxCount = 0;
        int count = 0;
        int size = nums.size();
        for(int i = 0 ; i < size ; i++){
            if(nums[i] > maxNum){
                maxNum = nums[i];
                count = 1;
                maxCount = 1;
                continue;
            }
            if(nums[i]!=nums[i-1]){
                count = 0;
            }    
            if(nums[i] == maxNum){
                count++;
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};