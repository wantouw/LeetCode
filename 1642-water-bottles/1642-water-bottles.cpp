class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = 0;
        result += numBottles;
        int filled = 1;
        while(filled > 0){
            filled = numBottles / numExchange;
            numBottles = numBottles % numExchange;
            result += filled;
            numBottles += filled;
        }
        return result;
    }
};