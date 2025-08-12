class Solution {
public:
    long long int dp[301][301] = {};
    long long power(int base, int exp) {
        long long res = 1;
        for (int i = 0; i < exp; ++i) {
            res *= base;
            if (res > 300) return 301; 
        }
        return res;
    }
    // long long int calc(int curr, long long int& result, int x, int remaining){
    //     if(dp[curr][remaining] > 0){
    //         cout << "curr: " << curr << " remaining: " << remaining << " 1" << endl;
    //         result++;
    //         return dp[curr][remaining];
    //     }
    //     if(dp[curr][remaining] == -1) return -1;
    //     long long int currResult = power(curr, x);
    //     if(currResult == remaining){
    //         result++;
    //         cout << "curr: " << curr << " remaining: " << remaining << " 2" << endl;
    //         dp[curr][remaining] = 1;
    //         return 1;
    //     }
    //     if(currResult > remaining){
    //         dp[curr][remaining] = -1;
    //         return -1;
    //     }
    //     long long int pos = 0;
    //     for(int i = curr+1 ; i <= remaining ; i++){
    //         pos+=max((long long int)0, calc(i, result, x, remaining - currResult));
    //     }
    //     return dp[curr][remaining] = pos;
    // }
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
        long long int result = 0;
        // for(int i = 1 ; i <= n ; i++){
        //     calc(i, result, x, n);
        // }
        return calc(1, x, n);
    }
};