class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lastSeen(30, 0), result(n, 1);
        for(int j = n-1 ; j >= 0 ; j--){
            for(int i = 0 ; i < 30 ; i++){
                if((nums[j] & (1 << i)) > 0){
                    // cout << "saw " << i << " on " << nums[j] << endl; 
                    lastSeen[i] = j;
                }
                result[j] = max(result[j], lastSeen[i] - j + 1);
            }
        }
        return result;
    }
};