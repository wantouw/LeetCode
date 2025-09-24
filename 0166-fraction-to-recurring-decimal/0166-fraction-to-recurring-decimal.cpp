class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        if(numerator == 0) return "0";
        long long first = abs((long long) numerator / denominator);
        if((numerator < 0) ^ (denominator < 0)){
            result += "-";
        }
        result += to_string(first);
        // numerator = abs(numerator);
        // denominator = abs(denominator);
        long long top = abs((long long)numerator);
        long long bottom = abs((long long) denominator);
        long long remainder = top % bottom;
        if(remainder == 0) return result;
        unordered_map<int, int> remainders;
        result+=".";
        int index = result.length();
        while(true){
            if(remainders[remainder] > 0){
                result = result.substr(0, remainders[remainder]) + "(" + result.substr(remainders[remainder]) + ")";
                break;
            }
            if(remainder == 0) break;
            remainders[remainder] = index;
            remainder*=10;
            first = remainder / bottom;
            result+=to_string(first);
            remainder %= bottom;
            index++;
        }
        return result;
    }
};