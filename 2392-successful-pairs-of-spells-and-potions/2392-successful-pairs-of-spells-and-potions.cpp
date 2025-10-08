class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success){
        vector<int> counts(100001, 0);
        int maxPotion = 0;
        for(auto potion: potions){
            counts[potion]++;
            maxPotion = max(maxPotion, potion);
        }
        for(int i = maxPotion - 1 ; i > 0 ; i--){
            counts[i]+=counts[i+1];
        }
        vector<int> result;
        long long int diff;
        for(auto spell: spells){
            diff = ceil(success * 1.0 / spell);
            if(diff > 100000) {
                result.push_back(0);
                continue;
            }
            // cout << "spell: " << spell << endl;
            // cout << diff << ' ' << counts[diff] << endl;
            result.push_back(counts[diff]);
        }
        return result;
    }
};