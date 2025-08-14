class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "";
        int max = -1;
        int curr = num[0] - '0';
        int count = 0;
        for(auto c: num){
            if(c - '0' == curr){
                count++;
            }
            else{
                curr = c - '0';
                count = 1;
            }
            if(count == 3){
                if(curr > max){
                    result = format("{}{}{}", curr, curr, curr);
                    max = curr;
                }
            }
        }
        return result;
    }
};