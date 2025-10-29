class Solution {
public:
    int smallestNumber(int n) {
        int highestPower = 1;
        while(true){
            if(n <= 0) break;
            n/=2;
            highestPower*=2;
        }
        return highestPower - 1;
    }
};