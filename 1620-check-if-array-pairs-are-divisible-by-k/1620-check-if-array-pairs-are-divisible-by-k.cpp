class Solution {
public:
    unordered_map<int, int> map;
    bool canArrange(vector<int>& arr, int k) {
        int cannots = 0;
        for (int i : arr) {
            int remainder = i % k;
            // cout << "i: " << i << "rem: " << remainder << endl;
            if (map[k - remainder] > 0) {
            // cout << i << " rem " << remainder << ' ' << k-remainder << endl;
                map[k - remainder]--;
                // map[remainder]--;
                cannots--;
            } else if (map[0 - remainder] > 0) {
            // cout << i << " rem " << remainder << ' ' << 0-remainder << endl;
                map[0 - remainder]--;
                // map[remainder]--;
                cannots--;
            } else if (map[-k - remainder] > 0) {
            // cout << i << " rem " << remainder << ' ' << 0-remainder << endl;
                map[-k - remainder]--;
                // map[remainder]--;
                cannots--;
            }else {
                cannots++;
                map[remainder]++;
            }
        }
        // cout << "cannots " << cannots << endl;
        if (cannots > 0)
            return false;
        return true;
    }
};