class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // vector<int> lastIdx(26, -1);
        // int count[26] = {};
        int result = 0;
        // int uniques[100005] = {};
        // int i = 0;
        // for(char c: s){
        //     // cout << lastIdx[c-'a'] << endl;
        //     if(i > 0) uniques[i]+=uniques[i-1];
        //     if(lastIdx[c-'a'] == -1) uniques[i]++;
        //     // else {

        //     //     cout << "uniques[i]: " << uniques[i] << ", uniques[lastIdx]: " << uniques[lastIdx[c-'a']] <<  endl;
        //     //     int unique = uniques[i] - uniques[lastIdx[c-'a']];
        //     //     cout << "unique: " << unique << endl;
        //     //     if(unique > 0) result+=unique;
        //     // }
        //     lastIdx[c-'a'] = i;
        //     count[c-'a']++;
        //     if(count[c-'a'] == 3) result++;
        //     // cout << uniques[i] << endl;
        //     i++;
        // }
        vector<int> leftBound(26, INT_MAX), rightBound(26, -1);
        int left = 0, right = s.length() - 1;
        // cout << result << endl;
        for(int i = 0 ; i < s.length() ; i++){
            // count[s[left+i] - 'a']++;
            if(i < leftBound[s[i] - 'a']) leftBound[s[i]-'a'] = i;
            if(i > rightBound[s[i] - 'a']) rightBound[s[i]-'a'] = i;
            // count[]
        }
        for(int i = 0; i < 26 ; i++){
            if(leftBound[i] == INT_MAX || leftBound[i] == rightBound[i]) continue;
            // cout << i << " " << leftBound[i] << " " << rightBound[i] << endl;
            int uniques = 0;
            int sign[26] = {};
            for(int j = leftBound[i] + 1 ; j < rightBound[i] ; j++){
                if(sign[s[j] - 'a'] == 0) uniques++;
                sign[s[j]-'a'] = 1;
            }
            // cout << i << " " << uniques[leftBound[i]] << " " << uniques[rightBound[i]] << endl;
            result += uniques;
        }
        return result;
    }
};