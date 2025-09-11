class Solution {
public:
    bool isVowel(char s){
        if(s == 'a' || s == 'i' || s == 'u' || s == 'e' || s == 'o' || s == 'A' || s == 'I' || s == 'U' || s == 'E' || s == 'O') return true;
        return false;
    }
    string sortVowels(string s) {
        vector<char> vowels;
        for(auto c: s){
            if(isVowel(c)){
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(), vowels.end());
        int idx = 0;
        for(char& c: s){
            if(isVowel(c)){
                c = vowels[idx++];
            }
        }
        return s;
    }
};