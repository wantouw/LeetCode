class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> curr;
        for(int i = 1 ; i <= numRows ; i++){
            curr.push_back(1);
            for(int j = 1 ; j <= i - 2 ; j++){
                // cout << i << " " << j << endl;
                curr.push_back(result[i-2][j-1] + result[i-2][j]);
            }
            curr.push_back(1);
            if(i == 1) curr.pop_back();
            result.push_back(curr);
            curr.clear();
        }
        return result;
    }
};