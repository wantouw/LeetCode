class Solution {
public:
    int height, width;
    int walk(int iMove, int jMove, int currI, int currJ, int expected, int turned, vector<vector<int>>& grid){
        currI += iMove;
        currJ += jMove;
        if(currI < height && currI >= 0 && currJ < width && currJ >= 0){
            if(grid[currI][currJ] == expected){
                int next = (expected == 2 ? 0 : 2);
                if(!turned){
                    int nextIMove = iMove, nextJMove = jMove;
                    if(iMove == -1 && jMove == 1){
                        nextIMove = 1;
                    }
                    else if(iMove == 1 && jMove == 1){
                        nextJMove = -1;
                    }
                    else if(iMove == 1 && jMove == -1){
                        nextIMove = -1;
                    }
                    else if(iMove == -1 && jMove == -1){
                        nextJMove = 1;
                    }
                    return 1 + max(
                        walk(nextIMove, nextJMove, currI, currJ, next, 1, grid),
                        walk(iMove, jMove, currI, currJ, next, 0, grid)
                    );
                }
                return 1 + walk(iMove, jMove, currI, currJ, next, 1, grid);
            }
        }
        return 0;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();
        int result = 0;
        for(int i = 0 ; i < height ; i++){
            for(int j = 0 ; j < width ; j++){
                if(grid[i][j] == 1){
                    result = max(result, 1 + walk(-1, 1, i, j, 2, 0, grid));
                    result = max(result, 1 + walk(1, 1, i, j, 2, 0, grid));
                    result = max(result, 1 + walk(1, -1, i, j, 2, 0, grid));
                    result = max(result, 1 + walk(-1, -1, i, j, 2, 0, grid));
                }
            }
        }
        return result;
    }
};