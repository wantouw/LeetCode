class Solution {
public:
    int maximumLength(vector<int>& nums) {
        nums[0] = nums[0]%2;
        int zigzag = nums[0];
        int continuous = nums[0];
        int zigzagCount = 1;
        int continuousCount = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i]%2 != zigzag){
                zigzagCount++;
                zigzag = nums[i]%2;
            }
            if(nums[i]%2 == continuous){
                continuousCount++;
            }
        }
        if(continuousCount<=nums.size()/2) continuousCount = nums.size() - continuousCount;
        return max(zigzagCount, continuousCount);
    }
};