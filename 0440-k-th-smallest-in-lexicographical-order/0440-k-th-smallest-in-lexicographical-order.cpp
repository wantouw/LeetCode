class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while(k > 0){
            int diff = countSubTree(n, curr, curr+1);
            if(diff<=k){
                curr++;
                k-=diff;
            }
            else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }

    int countSubTree(int n, long firstNum, long secondNum){
        int steps = 0;
        while(firstNum <= n){
            steps+=min((long)n+1, secondNum) - firstNum;
            firstNum*=10;
            secondNum*=10;
        }
        return steps;
    }
};