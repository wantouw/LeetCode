class Solution {
public:
    double dp[250][250]; 
    double recur(int a, int b){
        if(a <= 0 && b > 0) return 1;
        if(a <= 0 && b <= 0) return 0.5;
        if(a > 0 && b <= 0) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        return dp[a][b] = 0.25 * (recur(a - 4, b) + recur(a - 3, b - 1) 
            + recur(a - 2, b - 2) + recur (a - 1, b - 3));
    }
    double soupServings(int n) {
        if(n > 5000) return 1;
        fill(&dp[0][0], &dp[0][0] + 250 * 250, -1);
        int maxServing = ceil(n/25.0);
        return recur(maxServing, maxServing);
    }
};