class Trie {
    Trie* children[26];
    int count;
    public:
    Trie(){
        for(int i = 0 ; i < 26 ; i++){
            children[i] = nullptr;
        }
        count = 1;
    }
    void insert(string word){
        Trie* curr = this;
        for(char letter: word){
            int idx = letter - 'a';
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new Trie();
                // curr->children[idx]->count++;
                // cout << letter << " score : " << curr->children[idx]->count << endl;
            }
            else{
                curr->children[idx]->count++;
                // cout << letter << " score : " << curr->children[idx]->count << endl;
            }
            curr = curr->children[idx];
        }
    }
    int findScore(string word){
        Trie* curr = this;
        int score = 0;
        for(char letter: word){
            int idx = letter - 'a';
            if(curr->children[idx]){
                score += curr->children[idx]->count;
            }
            else{
                continue;
            }
            curr = curr->children[idx];
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root = new Trie();
        for(string word: words){
            root->insert(word);
        }
        vector<int> result;
        for(string word: words){
            result.push_back(root->findScore(word));
        }
        return result;
    }
};