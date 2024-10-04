class Solution {
public:
    unordered_map<int, int> map;
    long long dividePlayers(vector<int>& skill) {
        int target = 0, sum = 0;
        for(int value: skill){
            map[value]++;
            sum+= value;
        }
        target = sum / (skill.size() / 2);
        long long int result = 0;
        // cout << target << endl;
        for(int value: skill){
            if(map[target - value] > 0){
                result+=value * (target - value);
                // cout << result << endl;
                map[target - value]--;
            }
            else if(map[target - value] == 0) return -1;
        }

        return result / 2;
    }
};