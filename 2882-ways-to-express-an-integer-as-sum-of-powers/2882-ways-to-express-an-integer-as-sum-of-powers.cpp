class Solution {
public:
    int dp[301][301] = {};
    int power(int base, int exp) {
        int res = 1;
        for (int i = 0; i < exp; ++i) {
            res *= base;
            if (res > 300) return 301; 
        }
        return res;
    }
    int calc(int curr, int x, int remaining){
        int result = power(curr, x);
        if(remaining == 0) return 1;
        if(remaining < 0 ) return 0;
        if(curr > remaining) return 0;
        if(dp[curr][remaining]!=0) return dp[curr][remaining];
        int include = calc(curr + 1, x, remaining - result);
        int exclude = calc(curr + 1, x, remaining);
        return dp[curr][remaining] = (include + exclude) % 1000000007;
    }
    int numberOfWays(int n, int x) {
        return calc(1, x, n);
    }
};