class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> storage;
        int singles = 0;
        for(char letter: s){
            if(letter == '('){
                storage.push(letter);
            }
            else if(letter == ')'){
                if(!storage.empty()){
                    storage.pop();
                }
                else{
                    singles++;
                }
            }
        }
        return singles + storage.size();
    }
};