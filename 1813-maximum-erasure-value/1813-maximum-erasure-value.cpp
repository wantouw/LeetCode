class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> map;
        int result = 0;
        int curr = 0;
        int lower = 0;
        int idx = 0;
        for(auto num: nums){
            while(map[num] != 0 && idx != lower){
                int start = nums[lower];
                map[start]--;
                curr -= start;
                lower++;
            }
            map[num]++;
            curr += num;
            result = max(curr, result);
            // cout << num << ", res: " << result << endl;
            idx++;
        }
        return result;
    }
};