class Solution {
public:

    vector<vector<int>> atlantic;
    vector<vector<int>> pacific;
    int length, width;

    int dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& sea){
        if(i < 0 || j < 0 || i >= length || j >= width){
            return 0;
        }
        if(sea[i][j]) return sea[i][j];
        sea[i][j] = 1;
        if(i > 0 && heights[i-1][j] >= heights[i][j]){
            dfs(i-1, j, heights, sea);
        }
        if(j > 0 && heights[i][j-1] >= heights[i][j]){
            dfs(i, j-1, heights, sea);
        }
        if(j < width - 1 && heights[i][j+1] >= heights[i][j]){
            dfs(i, j+1, heights, sea);
        }
        if(i < length - 1 && heights[i+1][j] >= heights[i][j]){
            dfs(i+1, j, heights, sea);
        }
        return 0;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        length = heights.size();
        width = heights[0].size();
        atlantic = vector<vector<int>>(heights.size(), vector<int>(heights[0].size(), 0));
        pacific = vector<vector<int>>(heights.size(), vector<int>(heights[0].size(), 0));
        for(int i = 0 ; i < length ; i++){
            dfs(i, 0, heights, pacific);
            dfs(i, width - 1, heights, atlantic);
        }
        for(int i = 0 ; i < width ; i++){
            dfs(0, i, heights, pacific);
            dfs(length - 1, i, heights, atlantic);
        }
        vector<vector<int>> result;
        for(int i = 0 ; i < heights.size() ; i++){
            for(int j = 0 ; j < heights[i].size() ; j++){
                if(pacific[i][j] && atlantic[i][j]) result.push_back(vector<int>{i, j});
            }
        }
        return result;
    }
};