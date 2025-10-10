class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        for(int i = k ; i < energy.size() ; i++){
            if(energy[i-k] > 0) energy[i]+=energy[i-k];
        }
        int result = energy[energy.size()-1];
        for(int i = energy.size() - 1 ; energy.size() - i <= k ; i--){
            result = max(result, energy[i]);
        }
        return result;
    }
};