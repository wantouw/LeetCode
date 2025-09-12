class Solution {
public:
    bool isVowel(char c){
        switch(c){
            case 'a':
            case 'i':
            case 'u':
            case 'e':
            case 'o':
                return true;
            default:
                return false;
        }
    }

    bool doesAliceWin(string s) {
        int evenCount = 0, oddCount = 0;
        int count = 0;
        for(char c: s){
            if(isVowel(c)){
                count++;
            } 
        }
        if(count > 0) return true;
        return false;
    }
};