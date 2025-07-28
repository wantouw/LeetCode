class Solution {
public:
    int recursiveOr(vector<int>& nums, int size, int index, int cumulativeOr, int max, int& result){
        if(index == size - 1){
            if(cumulativeOr == max) return 1;
            return 0;
        }
        if(cumulativeOr == max){
            return 1 << (size - index - 1);
        }
        return recursiveOr(nums, size, index+1, cumulativeOr | nums[index+1], max, result) + 
            recursiveOr(nums, size, index+1, cumulativeOr, max, result);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        int result = 0;
        int size = nums.size();
        for(auto num: nums){
            maxOr|=num;
        }
        return recursiveOr(nums, size, 0, 0 | nums[0], maxOr, result) + recursiveOr(nums, size, 0, 0, maxOr, result) ;
    }
};