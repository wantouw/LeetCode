class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, stack<int>> map;
        for(int i = 0 ; i < nums.size() ; i++){
            map[nums[i]].push(i);
            // cout << map[nums[i]].top() << endl;
        }
        vector<int> result;
        for(int i = 0 ; i < nums.size() ; i++){
            if(map[(target - nums[i])].size() > 0){
                if(nums[i] == target / 2 && map[nums[i]].size() < 2) continue;
                result.push_back(map[(target - nums[i])].top()); map[(target - nums[i])].pop();
                result.push_back(map[nums[i]].top()); map[nums[i]].pop();
            // cout << nums[i] << endl;
                return result;
            } 
        }
        return result;
        
    }
};