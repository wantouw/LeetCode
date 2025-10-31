class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int tracker[105] = {};
        vector<int> result;
        for(auto num: nums){
            // tracker[num]++;
            if(++tracker[num] > 1) result.push_back(num);
        }
        return result;
    }
};