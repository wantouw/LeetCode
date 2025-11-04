class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> counts(51, 0);
        vector<pair<int, int>> pairs;
        vector<int> result;
        // for (int j = 0; j < k; j++)
        // {
        // 	counts[nums[j]]++;
        // }
        // for (int j = 0; j < k; j++)
        // {
        // 	if(counts[nums[j]] > 0) pairs.push_back({counts[nums[j]], nums[j]});
        // 	counts[nums[j]] = 0;
        // }
        // sort(pairs.begin(), pairs.end());
        // // for (auto num : pairs)
        // // {
        // // 	cout << num.first << ' ' << num.second << endl;
        // // }
        int sum = 0;
        // for (int i = 1; i <= x; i++)
        // {
        // 	sum += pairs[pairs.size() - i].first * pairs[pairs.size() - i].second;
        // }
        // result.push_back(sum);
        // cout << sum << endl;
        for (int i = k - 1; i < nums.size(); i++)
        {
            sum = 0;
            // counts[nums[i - k]]--;
            pairs.clear();
            for (int j = i - k + 1; j <= k + (i - k); j++)
            {
                counts[nums[j]]++;
            }
            for (int j = i - k + 1; j <= k + (i - k); j++)
            {
                if(counts[nums[j]] > 0) pairs.push_back({counts[nums[j]], nums[j]});
                counts[nums[j]] = 0;
            }
            sort(pairs.begin(), pairs.end());
            // for (auto num : pairs)
            // {
            //     cout << num.first << ' ' << num.second << endl;
            // }
            for (int j = 1; j <= x; j++)
            {
                // cout << pairs.size() - j << endl;
                sum += pairs[pairs.size() - j].first * pairs[pairs.size() - j].second;
                if(pairs.size() - j == 0) break;
            }
            result.push_back(sum);
            // cout << sum << endl;
        }
        return result;
    }
};