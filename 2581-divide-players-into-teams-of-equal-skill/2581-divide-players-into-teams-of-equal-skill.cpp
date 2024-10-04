class Solution {
public:
    
    long long dividePlayers(vector<int>& skill) {
        // int target = 0, sum = 0;
        sort(skill.begin(), skill.end());
        // for(int value: skill){
        //     map[value]++;
        //     sum+= value;
        // }
        // target = sum / (skill.size() / 2);

        // cout << skill << endl;
        long long int result = 0;
        int target = skill[0] + skill[skill.size() - 1];
        int length = skill.size();
        for(int i = 0; i < length / 2 ; i++){
            // cout << skill[i] << endl;
            if(skill[i] + skill[length - 1 - i] == target){
                result += skill[i] * skill[length - i - 1];
            }
            else{
                return -1;
            }
        }

        return result;
    }
};