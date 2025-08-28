class Solution {
public:
    
    void swap(int& a, int& b){
        int c = a;
        a = b;
        b = c;
    }

    static bool comp(int a, int b){
        return a > b;
    }
    
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int length = grid.size();
        for(int i = 0 ; i < length ; i++){
            vector<int> diagonals;
            for(int j = 0 ; i + j < length ; j++){
                diagonals.push_back(grid[i+j][j]);
            }
            sort(diagonals.begin(), diagonals.end(), comp);
            for(int j = 0 ; i + j < length ; j++){
                grid[i+j][j] = diagonals[j];
            }
        }
        for(int i = 1 ; i < length ; i++){
            vector<int> diagonals;
            for(int j = 0 ; i + j < length ; j++){
                diagonals.push_back(grid[j][i + j]);
            }
            sort(diagonals.begin(), diagonals.end());
            for(int j = 0 ; i + j < length ; j++){
                grid[j][i + j] = diagonals[j];
            }
        }
        return grid;
    }
};