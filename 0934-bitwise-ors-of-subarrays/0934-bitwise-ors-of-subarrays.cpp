class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ors;
        unordered_set<int> curr;
        unordered_set<int> result;
        int size = arr.size();
        for(int i = 0 ; i < size; i++){
            curr.insert(arr[i]);
            result.insert(arr[i]);
            for(auto asd: ors){
                int res = asd | arr[i];
                curr.insert(res);
                result.insert(res);
            }
            ors = curr;
            curr.clear();
        }
        return result.size();
    }
};