class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int longestDiag = 0;
        int maxArea = 0;
        int diag = 0, area = 0;
        for(auto dimension: dimensions){
            diag = dimension[0] * dimension[0] + dimension[1] * dimension[1];
            area = dimension[0] * dimension[1]; 
            if(diag > longestDiag) {
                longestDiag = diag;
                maxArea = area;
            }
            if(diag == longestDiag){
                maxArea = max(area, maxArea);
            }
        }
        return maxArea;
    }
};