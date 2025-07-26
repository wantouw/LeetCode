class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        pair<int, int> leftLimit;
        leftLimit.first = 0;
        leftLimit.second = 0;
        unordered_map<int, pair<int, int>> rightLimit;
        // int size = n.size();
        long long int maxSurplus = 0;
        for(auto pairIdx: conflictingPairs){
            int high = max(pairIdx[0], pairIdx[1]);
            int low = min(pairIdx[0], pairIdx[1]);
            pair<int, int>& currPair = rightLimit[high];
            if(low > currPair.first){
                currPair.second = currPair.first;
                currPair.first = low;
            }
            else if(low > currPair.second){
                currPair.second = low;
            }
            // rightLimit[max(pairIdx[0], pairIdx[1])].push_back(min(pairIdx[0], pairIdx[1]));
        }
        vector<long long int> surplus(n);
        long long int ans = 0;
        for(int i = 1; i <= n ; i++){
            // for(auto left: rightLimit[i]){
            //     if(left > leftLimit.first){
            //         leftLimit.second = leftLimit.first;
            //         leftLimit.first = left;
            //     }
            //     else if(left > leftLimit.second){
            //         leftLimit.second = left;
            //     }
            // }
            pair<int, int> currPair = rightLimit[i];
            if(currPair.first > leftLimit.first){
                leftLimit.second = leftLimit.first;
                leftLimit.first = currPair.first;
                if(currPair.second > leftLimit.second){
                    leftLimit.second = currPair.second;
                }
            }
            else if(currPair.first > leftLimit.second){
                leftLimit.second = currPair.first;
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