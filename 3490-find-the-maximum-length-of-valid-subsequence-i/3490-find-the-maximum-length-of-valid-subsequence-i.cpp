class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // int continuousMax = 0;
        // int zigzagMax = 0;
        // int continuous = 0;
        // int zigzag = 0;
        // nums[0] = nums[0] % 2;
        // continuous = 1;
        // zigzag = 1;
        // for(int i = 1 ; i < nums.size() ; i++){
        //     if(nums[i] % 2 == nums[i-1]){
        //         continuous++;
        //         zigzag = 1;
        //         if(continuous > continuousMax) continuousMax = continuous;
        //     }
        //     else {
        //         zigzag++;
        //         continuous = 1;
        //         if(zigzag > zigzagMax) zigzagMax = zigzag;
        //     }
        //     nums[i] = nums[i]%2;
        // }
        // vector<int> zigzag;
        // vector<int> continuous;
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