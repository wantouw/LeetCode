class Solution {
public:
    vector<vector<int>> graph;
    vector<int> subTree;
    vector<unordered_set<int>> descendants;
    int n;
    
    void dfs(int node, int parent, int& total){
        descendants[node].insert(node);
        for(auto child: graph[node]){
            if(child!=parent){
                dfs(child, node, total);
            // cout << node << " child: " << child << endl;
                subTree[node]^=subTree[child];
                // cout << "subtree res: " << subTree[node] << endl;
                
                descendants[node].insert(descendants[child].begin(),
                    descendants[child].end());
            }
        }
        // cout << "descendants: " << endl;
        // for(auto descendant: descendants[node]){
        //     cout << descendant << " ";
        // }
        //         cout << endl;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        graph.assign(n, std::vector<int>());
        // subTree.assign(n, 0);
        descendants.assign(n, std::unordered_set<int>());
        int total = 0;
        for(auto num: nums){
            subTree.push_back(num);
            total^=num;
        }
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int minScore = INT_MAX;
        dfs(0, -1, total);
        // cout << "total: " << total << endl;
        for(int i = 1 ; i < n -1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                int val1 = 0, val2 = 0, val3 = 0;
                if(descendants[i].count(j) != 0){
                    // cout << "masuk 1" << endl;
                    val1 = subTree[j];
                    val2 = subTree[i] ^ subTree[j];
                    val3 = total ^ subTree[i];
                } 
                else if(descendants[j].count(i) != 0){
                    // cout << "masuk 2" << endl;
                    val1 = subTree[i];
                    val2 = subTree[j] ^ subTree[i];
                    val3 = total ^ subTree[j];
                } 
                else {
                    // cout << "masuk 3" << endl;
                    val1 = subTree[i];
                    val2 = subTree[j];
                    val3 = total ^ val1 ^ val2;
                } 
                // cout << "total: " << total << endl;
                // cout << "values: " << val1 << " " << val2 << " " << val3 << endl;
                int diff = max({val1, val2, val3}) - min({val1, val2, val3});
                minScore = min(minScore, diff);
            }
        }
        // cout << subTree[0] << endl;
        return minScore;
    }
};