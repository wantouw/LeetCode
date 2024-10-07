class Solution {
public:
    int nextViable(string s, int start, int length){
        for(int i = start ; i < length ; i++){
            if(s[i]!='x'){
                return i;
                
            }
        }
        return -1;
    }
    int prevViable(string s, int start, int length){
        for(int i = start ; i >= 0 ; i--){
            if(s[i]!='x'){
                return i;
                
            }
        }
        return 0;
    }
    int minLength(string s) {
        int length = s.length();
        int result = length;
        for(int i = 0 ; i < length - 1 ; i ++){
            int next =  nextViable(s, i+1, length);
            // cout << "first next: " << s[i] << next << endl;
            if(next == -1) continue;
            if(s[i] == 'A' && s[next] == 'B'){
                s[i] = 'x';
                s[next] = 'x';
                result-=2;
                i = prevViable(s, i-1, length) - 1;
            }
            next =  nextViable(s, i+1, length);
            if(next == -1 || i <= -1) continue;
            if(s[i] == 'C' && s[next] == 'D'){
                s[i] = 'x';
                s[next] = 'x';
                result-=2;
                i = prevViable(s, i-1, length) - 1;
            }
            // cout << s << endl;
        }
        return result;
    }
};