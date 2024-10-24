class Solution {
public:
    int fib(int n) {
        vector<int> fibo;
        fibo.push_back(0);
        fibo.push_back(1);
        int result;
        for(int i = 2; i <= n ; i++){
            result = fibo[i-1] + fibo[i-2];
            fibo.push_back(result);
        }
        return fibo[n];
    }
};