class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums[0] -= k;
        int border = nums[0];
        int result = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            int transformed = nums[i] - k;
            // cout << border << endl;
            if(transformed <= border){
                int diff = border - transformed + 1;
                if(abs(-1 * k + diff) <= k){
                    result++;
                    border = nums[i] - k + diff;
                    // 1   1   1   1  1
                    // -2  -1  0   1  2
                }
            }
            else {
                result++;
                border = transformed;
            }
        }
        return result;
    }
};