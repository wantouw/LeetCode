class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result = {};
        map<string, vector<int>> memo;
        int length = expression.length();
        if(length == 0) return result;
        if(length == 1){
            result.push_back(stoi(expression));
            return result;
        }
        if(length == 2 && isdigit(expression[0])){
            result.push_back(stoi(expression));
            return result;
        }
        if(memo.find(expression)!=memo.end()){
            return memo[expression];
        }
        for (int i = 0; i < length; i++) {
            if (expression[i] == '+' || expression[i] == '-' ||
                expression[i] == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right =
                    diffWaysToCompute(expression.substr(i + 1, length));
                for (int l : left) {
                    for (int r : right) {
                        switch (expression[i]) {
                        case '-':
                            result.push_back(l - r);
                            break;
                        case '+':
                            result.push_back(l + r);
                            break;
                        case '*':
                            result.push_back(l * r);
                            break;
                        }
                    }
                }
            }
        }
        memo[expression] = result;
        return result;
    }
};