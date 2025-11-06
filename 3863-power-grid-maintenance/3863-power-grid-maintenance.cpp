class Solution {
public:
    vector<int> parents;
    int unionFind(int a){
        if(parents[a] == a) return a;
        return parents[a] = unionFind(parents[a]);
    }
    void unionSet(int a, int b){
        int parentA = unionFind(a);
        int parentB = unionFind(b);
        if(parentA == parentB) return;

        parents[parentA] = parentB;
        //  = parents[b]
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parents = vector<int> (c+1, 0);
        unordered_map<int, set<int>> groups;
        vector<int> result;
        for(int i = 1 ; i <= c ; i++){
            parents[i] = i;
        }
        for(auto connection: connections){
            unionSet(connection[0], connection[1]);
            // cout << "parent: " << parents[connection[0]] << ", child: " << parents[connection[1]] << endl;
        }
        // cout << endl;
        for(int i = 1 ; i <= c ; i++){
            int parent = unionFind(i);
            groups[parent].insert(i);
            // cout << "parent: " << parent << ", child: " << i << endl;
        }
        for(auto query: queries){
            int target = query[1];
            int parent = parents[target];
            if(query[0] == 1){
                if(groups[parent].count(target)){
                    result.push_back(target);
                } else {
                    if(groups[parent].size() == 0) result.push_back(-1);
                    else result.push_back(*groups[parent].begin());
                }
            }
            else {
                groups[parent].erase(target);
            }
        }
        return result;
    }
};