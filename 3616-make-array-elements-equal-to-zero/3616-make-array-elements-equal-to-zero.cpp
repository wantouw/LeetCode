class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int> sums = vector<int>(nums.size(), 0);
        for(int i = 0 ; i < nums.size() ; i++){
            sums[i]+=nums[i];
            if(i > 0) sums[i]+=sums[i-1];
        }
        int result = 0;
        int left = 0, right = 0;
        for(int i = 0 ; i < nums.size() ;  i++){
            if(nums[i]!=0) continue;
            if(i > 0) left = sums[i-1];
            right = sums[nums.size() - 1] - sums[i];
            if(left == right) result += 2;
            else if(abs(left - right) == 1) result++;
        }
        return result;
    }
};