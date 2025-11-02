class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> peta(m+1, vector<int>(n+1, 0));
        // vector<vector<int>> blockedY(m+1, vector<int>(n+1, 0));
        int result = m * n;
        for(auto wall: walls){
            peta[wall[0]][wall[1]] = -1;
        }
        for(auto guard: guards){
            peta[guard[0]][guard[1]] = -1;
        }
        result-= walls.size();
        result -= guards.size();
        // cout << result << endl;
        for(auto guard: guards){
            int y = guard[0], x = guard[1];
            for(int i = y - 1 ; i >= 0 ; i--){
                if(peta[i][x] == -1 || peta[i][x] == 1){
                    break;
                }
                else {
                    // cout << i << " " << x << endl;
                    peta[i][x] = 1;
                    result--;
                }
            }
            for(int i = y + 1 ; i < m ; i++){
                if(peta[i][x] == -1 || peta[i][x] == 1){
                    break;
                }
                else {
                    // cout << i << " " << x << endl;
                    peta[i][x] = 1;
                    result--;
                }
            }
        }
        // cout << result << endl;
        for(auto guard: guards){
            int y = guard[0], x = guard[1];
            for(int i = x - 1 ; i >= 0 ; i--){
                if(peta[y][i] == -1 || peta[y][i] == 2){
                    break;
                }
                else if(peta[y][i] == 1) continue;
                else {
                    // cout << y << " " << i << endl;
                    peta[y][i] = 2;
                    result--;
                }
            }
            for(int i = x + 1 ; i < n ; i++){
                if(peta[y][i] == -1 || peta[y][i] == 2){
                    break;
                }
                else if(peta[y][i] == 1) continue;
                else {
                    // cout << y << " " << i << endl;
                    peta[y][i] = 2;
                    result--;
                }
            }
        }
        return result;
        // 0 0 G W 0 W W 
        // 0 G 0 0 0 G G
    }
};