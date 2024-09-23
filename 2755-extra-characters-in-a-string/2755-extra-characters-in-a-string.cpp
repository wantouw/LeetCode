class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int length = s.length();
        vector<int> dp(length+1, 0);
        for(int i = length - 1;i>=0;i--){
            dp[i] = dp[i+1]+1;
            for(int j = i;j<length;j++){
                string currString = s.substr(i, j-i+1);
                if(dict.count(currString) > 0){
                    dp[i] = min(dp[i], dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};