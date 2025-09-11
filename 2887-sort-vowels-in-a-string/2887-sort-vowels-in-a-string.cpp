class Solution {
public:
    bool isVowel(char s){
        if(s == 'a' || s == 'i' || s == 'u' || s == 'e' || s == 'o' || s == 'A' || s == 'I' || s == 'U' || s == 'E' || s == 'O') return true;
        return false;
    }
    string sortVowels(string s) {
        vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> counts;
        vector<int> positions;
        for(int i = 0 ; i < s.length() ; i++){
            if(isVowel(s[i])){
                counts[s[i]]++;
                positions.push_back(i);
            }
        }
        int start = 0;
        for(int i = 0 ; i < positions.size() ; i++){
            cout << vowels[start] << " " << counts[vowels[start]] << endl;
            // cout << counts[vowels[start]]] << endl;
            if(counts[vowels[start]] == 0){
                start++;
                i--;
                continue;
            }
            s[positions[i]] = vowels[start];
            counts[vowels[start]]--;
        }
        return s;
    }
};