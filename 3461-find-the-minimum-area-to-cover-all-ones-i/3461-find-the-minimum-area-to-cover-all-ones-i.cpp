class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int topRightI = 1005;
        int topRightJ = 0;
        int bottomLeftI = 0;
        int bottomLeftJ = 1005;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    if(j > topRightJ){
                        topRightJ = j;
                    }
                    if(i < topRightI){
                        topRightI = i;
                    }
                    if(j < bottomLeftJ){
                        bottomLeftJ = j;
                    }
                    if(i > bottomLeftI){
                        bottomLeftI = i;
                    }
                }
            }
        }
        // cout << topRightI << " " << topRightJ << " " << bottomLeftI << " " << bottomLeftJ << endl;
        return (topRightJ - bottomLeftJ + 1) * (bottomLeftI - topRightI + 1);
    }
};