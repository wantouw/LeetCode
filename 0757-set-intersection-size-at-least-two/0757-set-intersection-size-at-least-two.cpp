class Solution {
public:
    static bool customComparator(vector<int> a, vector<int> b){
        // return a[1] < b[1];
        if(a[1] == b[1]){
            return a[0] > b[0];
        }
        return a[1] < b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), customComparator);
        // vector<int> result;
        int a, b;
        int result = 2;
        for(int i = 0 ; i < intervals.size() ; i++){
            // cout << intervals[i][0] << " " << intervals[i][1] << endl;
            if(i == 0){
                // result.push_back(intervals[i][1] - 1);
                // result.push_back(intervals[i][1]);
                a = intervals[i][1]-1;
                b = intervals[i][1];

            }
            else {
                int lower = intervals[i][0], upper = intervals[i][1];
                if(b < lower) {
                    result+=2;
                    a = upper - 1;
                    b = upper;
                }
                else if(a < lower){
                    result++;
                    a = b;
                    b = upper;
                }
            }
        }
        return result;
    }
};