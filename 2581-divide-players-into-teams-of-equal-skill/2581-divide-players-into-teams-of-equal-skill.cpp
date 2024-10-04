class Solution {
public:
    
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long int result = 0;
        int length = skill.size();
        int target = skill[0] + skill[length - 1];
        for(int i = 0; i < length / 2 ; i++){
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