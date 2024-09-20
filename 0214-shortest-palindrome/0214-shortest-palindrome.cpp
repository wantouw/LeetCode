class Solution {
public:
    string shortestPalindrome(string s) {
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        string combined = s + '#' + reversed;
        string result;
        cout << combined << endl;
        int length = combined.length();
        vector<int> prefixTable(length, 0);
        int index = 0;
        int check = 1;
        while(check < length){
            if(combined[index] == combined[check]){
                 prefixTable[check] = ++index;
                 
                check++;
            }
            else{
                if(index > 0){
                    index = prefixTable[index - 1];
                    // check--;
                }
                else{
                    check++;
                    
                }
            }
            // prefixTable[check] = index;
            // check++;
        }
        cout << reversed.length()  - prefixTable[length - 1]<< endl;
        result = reversed.substr(0, reversed.length()  - prefixTable[length - 1]) + s;
        return result;
    }
};