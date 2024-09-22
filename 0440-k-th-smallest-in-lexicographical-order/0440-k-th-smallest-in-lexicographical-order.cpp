class Solution {
public:
    // int test(int value, int max, int &index, int target){
    //     int result;
    //     if(value > max) return -1;
    //     if(value != 0) index++;
    //     if(index == target) return value;
    //     if(value != 0) result = test(value * 10, max, index, target);
    //     if(result != -1) return result;
    //     result = test(value * 10 + 1, max, index, target);
    //     if(result != -1) return result;
    //     result = test(value * 10 + 2, max, index, target);
    //     if(result != -1) return result;
    //     result = test(value * 10 + 3, max, index, target);
    //     if(result != -1) return result;
    //     result = test(value * 10 + 4, max, index, target);
    //     if(result != -1) return result;
    //     result = test(value * 10 + 5, max, index, target);
    //     if(result != -1) return result;
    //     result = test(value * 10 + 6, max, index, target);
    //     if(result != -1) return result;
    //     result = test(value * 10 + 7, max, index, target);
    //     if(result != -1) return result;
    //     result = test(value * 10 + 8, max, index, target);
    //     if(result != -1) return result;
    //     result = test(value * 10 + 9, max, index, target);
    //     if(result != -1) return result;
    //     return -1;
    // }
    // int 
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