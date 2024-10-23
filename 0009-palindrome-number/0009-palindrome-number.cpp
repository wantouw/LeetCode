class Solution {
public:
    bool isPalindrome(int x) {
        string result = to_string(x);
        int length = result.length();
        for(int i = 0 ; i <= length / 2 ; i++){
            if(result[i] != result[length - i - 1]){
                // cout << result[i] << result[length - 1] << 'a' << endl;
                return false;
            }
        }
        return true;
    }
};