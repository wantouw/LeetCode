class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        // cout << folder;
        vector<string> result;
        int size = folder.size();
        int parentIndex = 0;
        for(int i = 1 ; i < size ; i++){
            if(!folder[i].starts_with(folder[parentIndex] + "/")){
                result.push_back(folder[parentIndex]);
                parentIndex = i;
            }
            if(i == size-1){
                result.push_back(folder[parentIndex]);
            }
        }
        return result;
    }
};