class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> map;
        int max = 0;
        int largest = INT_MIN;
        for(auto num: nums){
            if(num > 0){
                map[num]++;
            }
            if(map[num] == 1) max+=num;
            if(num > largest) largest = num;
        }
        if(largest < 0) return largest;
        return max;
    }
};