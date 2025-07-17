class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int seq = 0;
        int size = nums.size();
        int tracker[1001][1001] = {0};
        for(int i = 1 ; i < size ; i++){
            for(int j = 0 ; j < i ; j++){
                int remainder = (nums[i] + nums[j]) % k;
                tracker[i][remainder] = tracker[j][remainder] + 1;
                seq = max(seq, tracker[i][remainder]);
            }
        }
        return seq + 1;
    }
};