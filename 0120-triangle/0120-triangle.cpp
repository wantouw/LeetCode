class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        if(height == 1) return triangle[0][0];
        int result = INT_MAX;
        int curr = 0;
        for(int i = 1 ; i < height ; i++){
            for(int j = 0 ; j <= i ; j++){
                curr = triangle[i][j];
                if(j == i){
                    triangle[i][j] = curr + triangle[i-1][j-1];
                }
                else if(j > 0){
                    triangle[i][j] = min(curr + triangle[i-1][j], curr + triangle[i-1][j-1]);
                }
                else {
                    triangle[i][j] = curr + triangle[i-1][j];
                }
                if(i == height - 1){
                    result = min(result, triangle[i][j]);
                }
            }
        }
        return result;
    }
};