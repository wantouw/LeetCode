class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int i = 0;
        for(int i = 0 ; i < 31 ; i++){
            if((n & (1 << i)) != 0) powers.push_back(1 << i);
            // if((n & (1 << i)) != 0) cout << (1 << i) << " ";
        }
        vector<int> results;
        for(auto query: queries){
            int start = query[0], end = query[1];
            long long int result = powers[start];
            for(int i = start+1 ; i <= end ; i++){
                result *= powers[i];
                result %= 1000000007;
            }
            results.push_back(result);
        }
        return results;
    }
};