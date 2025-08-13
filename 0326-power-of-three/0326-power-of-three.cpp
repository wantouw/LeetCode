class Solution {
public:
    bool isPowerOfThree(int n) {
        while(true){
            if(n <= 0) return false;
            if(abs(n) == 1) return true;
            if(n % 3 == 0){
                n/=3;
            }
            else {
                return false;
            }
        }
    }
};