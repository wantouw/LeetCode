class Solution {
public:
    int minSwaps(string s) {
        stack<char> storage;
        int baddies = 0;
        for(char c: s){
            if(c == '['){
                storage.push(c);
            }
            else{
                if(!storage.empty()){
                    storage.pop();
                }
                else{
                    baddies++;
                }
            }
        }
        return (baddies+1)/2;
    }
};