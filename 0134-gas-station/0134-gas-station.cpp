class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = -1;
        int size = gas.size();
        vector<int> remainingAfterMove(size);
        int sumCheck = 0;
        int startIndex = 0;
        int biggestLife = 0;
        for(int i = 0 ; i < size  ; i++){
            remainingAfterMove[i] = -cost[i] + gas[i];
            sumCheck += remainingAfterMove[i];
        }
        if(sumCheck < 0){
            return -1;
        }
        startIndex = 0;
        biggestLife+=remainingAfterMove[0];
        for(int i = 1 ; i < size ; i++){
            if(biggestLife < 0){
                startIndex = i;
                biggestLife = remainingAfterMove[i];
            }
            else {
                biggestLife+=remainingAfterMove[i];
            }
        }
        return startIndex;
    }
};