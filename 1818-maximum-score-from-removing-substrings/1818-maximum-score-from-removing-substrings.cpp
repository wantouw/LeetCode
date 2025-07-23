class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // stack<char> removed;
        int points = 0;
        int size = s.size();
        if(x > y){
            for(int i = 1 ; i < size ; i++){
                if(s[i] == 'b' && i - 1 >= 0 && s[i-1] == 'a'){
                    // cout << "kena" << endl;
                    points+=x;
                    // removed = removed.substr(0, removedSize-1);
                    // s = s.substr(0, i-1) + s.substr(i+1);
                    s.erase(i-1, 2);
                    size-=2;
                    i-=2;
                    // removedSize--;
                }
                // cout << "hai " << removed << endl;
            }
            // cout << "size: " << removedSize << endl;
            for(int i = 1 ; i < size ; i++){
                if(s[i] == 'a' && i - 1 >= 0 && s[i-1] == 'b'){
                // cout << removed[i] << " " << removed[i-1] << endl;
                    // cout << "kena" << endl;
                    points+=y;
                    s.erase(i-1, 2);
                    size-=2;
                    i-=2;
                }
                // cout << "second " << removed << endl;
            }
        }
        else {
            for(int i = 1 ; i < size ; i++){
                if(s[i] == 'a' && i - 1 >= 0 && s[i-1] == 'b'){
                    // cout << "kena" << endl;
                    points+=y;
                    // removed = removed.substr(0, removedSize-1);
                    s.erase(i-1, 2);
                    size-=2;
                    i-=2;
                    // removedSize--;
                }
                // cout << "hai " << removed << endl;
            }
            // cout << "size: " << removedSize << endl;
            for(int i = 1 ; i < size ; i++){
                // cout << removed[i] << " " << removed[i-1] << endl;
                if(s[i] == 'b' && i - 1 >= 0 && s[i-1] == 'a'){
                    // cout << "kena" << endl;
                    points+=x;
                    s.erase(i-1, 2);
                    size-=2;
                    i-=2;
                }
                // cout << "second " << removed << endl;
            }
        }
        return points;
    }
};