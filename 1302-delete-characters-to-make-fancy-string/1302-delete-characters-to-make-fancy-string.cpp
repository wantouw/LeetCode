class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        char curr = s[0];
        int count = 0;
        for(auto character: s){
            if(character == curr){
                count++;
                if(count <= 2) res += character;
            }
            else {
                curr = character;
                count = 1;
                res += character;
            }
        }
        return res;
    }
};