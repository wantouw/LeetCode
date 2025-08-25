class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        // 0 0 

        // 0 1
        // 1 0
        
        // 0 2
        // 1 1 
        // 2 0
        
        // 1 2
        // 2 1

        // 2 2

        // for(int i = 0 ; i < mat.size() ; i++){
        //     for(int j = i ; j < mat[0].size() ; j++){
        //         for(int k = i ; k <= j ; k++){
        //             result.push_back(mat[k][j-(k-i)]);
        //             cout << mat[k][j-(k-i)] << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }

        int i = 0, j = 0;
        int width = mat[0].size();
        int height = mat.size();
        int direction = 1;
        while(i < height && j < width){
            // cout << i << " " << j << endl;
            result.push_back(mat[i][j]);
            // cout << mat[i][j] << " ";
            if(direction){
                if(i - 1 >= 0 && j + 1 < width){
                    i--;
                    j++;
                }
                else if(j + 1 < width){
                    j++;
                    direction = 0;
                }
                else{
                    i++;
                    direction = 0;
                }
            }
            else{
                if(i + 1 < height && j - 1 >= 0){
                    i++;
                    j--;
                }
                else if(i + 1 < height){
                    i++;
                    direction = 1;
                }
                else{
                    j++;
                    direction = 1;
                }
            }
        }

        return result;
    }
};