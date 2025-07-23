class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int points = 0;
        char first = 'b';
        char second = 'a';
        int count1 = 0, count2 = 0;
        int high = y;
        int low = x;
        if(x > y){
            first = 'a';
            second = 'b';
            high = x;
            low = y;
        }
        for(char c: s){
            if(c == first){
                count1++;
            }
            else if(c == second){
                if(count1 > 0){
                    count1--;
                    points+=high;
                } else {
                    count2++;
                }
            }
            else{
                points+= min(count2, count1) * low;
                count1=0;
                count2=0;
            }
        }
        if(count1 > 0){
            points+= min(count2, count1) * low;
        }
        return points;
    }
};