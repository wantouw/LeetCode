class Solution {
public:
    bool static comparePair(pair <int, int> x, pair<int, int> y){
        return x.second < y.second;
    }
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> arrIdx;
        int length = arr.size();
        for(int i = 0; i < length;i++){
            arrIdx.push_back({i, arr[i]});
        }
        
        sort(arrIdx.begin(), arrIdx.end(), comparePair);
        vector<int> result(length,0);
        if(length == 0) return result;
        int curr = arrIdx[0].second;
        int currRank = 1;
        for (auto i = arrIdx.begin(); i != arrIdx.end(); i++) {
            if (i->second != curr) {
                curr = i->second;
                currRank++;
            }
            result[i->first] = currRank;
        }
        return result;
    }
};