class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int height = mat.size();
        int width = mat[0].size();
        vector<int> heights(width);
        int result = 0;
        for(int i = 0 ; i < height ; i++){
            for(int j = 0 ; j < width ; j++){
                if(mat[i][j] == 1){
                    heights[j] = heights[j] + 1;
                } else {
                    heights[j] = 0;
                }
            }
            vector<int> sum(width);
            stack<int> st;
            for(int j = 0 ; j < width ; j++){
                while(!st.empty() && heights[st.top()] >=  heights[j]) st.pop();
                if(!st.empty()){
                    int top = st.top();
                    sum[j] = sum[top] + heights[j] * (j - top);
                } else {
                    sum[j] = heights[j] * (j + 1);
                }
                st.push(j);
                result += sum[j];
            }
        }
        return result;
    }
};