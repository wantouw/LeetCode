class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        // for(auto point: points){
        //     cout << point[0] << " " << point[1] << endl;
        // }
        int result = 0;
        for(int i = 0 ; i < points.size() - 1 ; i++){
            int yMax = 55, yCurr = points[i][1];
            for(int j = i+1 ; j <  points.size() ; j++){
                int yIter = points[j][1];
                if(yIter >= yCurr && yIter < yMax){
                    result++;
                    yMax = yIter;
                }
            }
        }
        return result;
    }
};