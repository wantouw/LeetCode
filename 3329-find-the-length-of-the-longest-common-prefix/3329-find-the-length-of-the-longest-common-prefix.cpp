
class TrieNode {
    public:
        TrieNode* children[10];
        TrieNode(){
            for(int i = 0 ; i < 10 ; i++){
                children[i] = nullptr;
            }
        }

        void insert(int num){
            TrieNode* curr = this   ;
            string numString = to_string(num);
            for(char digit: numString){
                int index = digit - '0';
                if(curr->children[index] == nullptr){
                    // cout << "hello " << index <<  endl;
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
            }
        }

        int findLongestPrefix(int num){
            string numString = to_string(num);
            int length = 0;
            TrieNode* curr = this;
            for(char digit: numString){
                int index = digit - '0';
                if(curr->children[index] == nullptr){
                    // cout << "hello " << index <<  endl;
                    break;
                }
                else{
                    length++;
                    // cout << index << " index" << endl;
                    curr = curr->children[index];
                }
            }
            // cout << length << "length" << endl;
            return length;
        }
};

class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        void insert(int num){

        }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();
        for(int num: arr1){
            root->insert(num);
        }

        int longestPrefix = 0;
        for(int num: arr2){
            int longest = root->findLongestPrefix(num);
            // cout << "longest" << longest << "prefix" << longestPrefix << endl;
            longestPrefix = max(longest, longestPrefix);
            // cout << longestPrefix << endl;
        }
        // cout << "ans" << longestPrefix << endl;
        return longestPrefix;
    }
};