class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string word = "";
        unordered_map<string, int> map;
        int index = 0;
        vector<string> answers;
        // cout << s1.size() << ' ' << s1 << '\n';
        for(int i = 0;i<s1.size();i++){
            // cout << i << s1.size() - 1 << endl;
            if(s1[i]!=' '){
                word += s1[i];
                // cout << word << s1[i] << '\n';
            }
            if(s1[i] == ' ' || i == s1.size() - 1) {
                // cout << "halo" << '\n';
                cout << word << '\n';
                map[word]++;
                // index = 0;
                word = "";
            }
        }
        for(int i = 0;i<s2.size();i++){
            if(s2[i]!=' '){
                word += s2[i];
                // cout << word << s1[i] << '\n';
            }
            if(s2[i] == ' ' || i == s2.size() - 1) {
                cout << word << '\n';
                map[word]++;
                // index = 0;
                word = "";
            }
        }
        for(auto itr = map.begin();itr!=map.end();itr++){
            if(itr->second == 1){
                // cout << itr->first << ' ' << itr->second << '\n';
                answers.push_back(itr->first);
            }
        }
        return answers;
    }
};