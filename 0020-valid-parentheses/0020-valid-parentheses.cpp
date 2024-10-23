class Solution {
public:
    bool isValid(string s) {
        stack<char> resStack;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                resStack.push(s[i]);
            }
            else if(s[i] == ')'){
                if(resStack.size() == 0) return false;
                if(resStack.top() == '(') resStack.pop();
                else return false;
            }
            else if(s[i] == '}'){
                if(resStack.size() == 0) return false;
                if(resStack.top() == '{') resStack.pop();
                else return false;
            }
            else if(s[i] == ']'){
                if(resStack.size() == 0) return false;
                if(resStack.top() == '[') resStack.pop();
                else return false;
            }
        }
        if(resStack.size() != 0) return false;
        return true;
    }
};