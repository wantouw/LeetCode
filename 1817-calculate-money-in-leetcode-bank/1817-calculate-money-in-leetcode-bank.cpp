class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int multiplier = 1;
        int track = 0;
        for(int i = 0; i < weeks ; i++){
            track+=multiplier;
            multiplier++;
        }
        int one = 21;
        int result = weeks * one + (7 * track);
        int left = n % 7;
        // cout << result << endl;
        for(int i = 0 ; i < left ; i++){
            result += i + (weeks + 1);
        }
        return result;
    }
};