class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> set;
        int max = 0;
        int largest = INT_MIN;
        for(auto num: nums){
            if(num > 0){
                if(set.count(num) == 0) max+=num;
                set.insert(num);
            }
            if(num > largest) largest = num;
        }
        if(largest < 0) return largest;
        return max;
    }
};