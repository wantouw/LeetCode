class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp(height, vector<int>(width, 0));
        for(int i = 0 ; i < height ; i++){
            for(int j = 0 ; j < width ; j++){
                if(matrix[i][j] == 1){
                    if(i > 0 && j > 0){
                        int minSquare = min(dp[i-1][j], dp[i-1][j-1]);
                        minSquare = min(minSquare, dp[i][j-1]);
                        dp[i][j] = minSquare + 1;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                    result += dp[i][j];
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        // 0 1 1 1 [0 1 1 1]
        // 1 1 1 1 [1 1 2 2]
        // 0 1 1 1 [0 1 2 3]
        return result;
    }
};