class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n, 0);
        dp[0] = 1;
        long long result = 0;
        int start = -1, end = -1;
        for(int i = 0 ; i < n ; i++){
            result += dp[i];
            if(dp[i] <= 0) continue;
            start = i + delay;
            end = i + forget;
            for(int j = start ; j < end && j < n ; j++){
                dp[j] += dp[i] % 1000000007;
            }
            if(end < n) result -= dp[i];
            result %= 1000000007;
        }
        return result;
    }
};