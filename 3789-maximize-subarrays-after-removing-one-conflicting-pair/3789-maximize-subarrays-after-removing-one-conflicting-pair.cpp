class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        pair<int, int> leftLimit;
        leftLimit.first = 0;
        leftLimit.second = 0;
        unordered_map<int, vector<int>> rightLimit;
        // int size = n.size();
        long long int maxSurplus = 0;
        for(auto pair: conflictingPairs){
            rightLimit[max(pair[0], pair[1])].push_back(min(pair[0], pair[1]));
        }
        vector<long long int> surplus(n);
        long long int ans = 0;
        for(int i = 1; i <= n ; i++){
            for(auto left: rightLimit[i]){
                if(left > leftLimit.first){
                    leftLimit.second = leftLimit.first;
                    leftLimit.first = left;
                }
                else if(left > leftLimit.second){
                    leftLimit.second = left;
                }
            }
            ans += i - leftLimit.first;
            // cout << i << " " << leftLimit.first << " " << leftLimit.second << endl;
            surplus[leftLimit.first] += leftLimit.first - leftLimit.second;
            maxSurplus = max(surplus[leftLimit.first], maxSurplus);
        }
        // int maxSurplus = max_element(surplus.begin(), surplus.end());
        // cout << "max: " << maxSurplus << endl;
        return ans + maxSurplus;
    }
};