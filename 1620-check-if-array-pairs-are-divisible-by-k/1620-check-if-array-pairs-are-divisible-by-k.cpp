class Solution {
public:
    unordered_map<int, int> map;
    bool canArrange(vector<int>& arr, int k) {
        int cannots = 0;
        for (int i : arr) {
            int remainder = (i % k + k) % k;
            if (map[k - remainder] > 0) {
                map[k - remainder]--;
                cannots--;
            } else if (map[0 - remainder] > 0) {
                map[0 - remainder]--;
                cannots--;
            }else {
                cannots++;
                map[remainder]++;
            }
        }
        if (cannots > 0)
            return false;
        return true;
    }
};