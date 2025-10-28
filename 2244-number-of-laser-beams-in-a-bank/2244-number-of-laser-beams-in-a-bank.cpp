class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevRow = 0, currRow = 0;
        int result = 0;
        for(int i = 0 ; i < bank.size() ; i++){
            if(currRow >= 1) prevRow = currRow;
            currRow = 0;
            for(char c: bank[i]){
                if(c == '1'){
                    currRow++;
                }
            }
            result += currRow * prevRow;
        }
        return result;
    }
};