class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count;
        for(auto num: basket1){
            count[num]++;
        }
        for(auto num: basket2){
            count[num]--;
        }
        int minValue = INT_MAX;
        vector<int> excess;
        for(auto [key, value]: count){
            // cout << key << " " << value << endl;
            minValue = min(minValue, key);
            if(value % 2 == 1){
                return -1;
            }
            for(int i = 0 ; i < abs(value / 2) ; i++){
                excess.push_back(key);
            }
        }
        // 3 4 4 4 4
        // 3 5 5 5 5
        long long int result = 0;
        sort(excess.begin(), excess.end());
        for(int i = 0 ; i < excess.size()/2 ; i++){
            result += min(excess[i], minValue * 2);
        }
        return result;
    }
};