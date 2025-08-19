class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int result = 0;
        unordered_map<int, int> map;
        int multiplier = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                result += multiplier++;
            }
            else{
                multiplier = 1;
            }
        }
        return result;
    }
};