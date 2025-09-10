class Solution {
public:

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<bitset<501>> learned(languages.size()+5);
        for (int i = 0; i < languages.size(); i++)
        {
            for (int j = 0; j < languages[i].size(); j++)
            {
                learned[i][languages[i][j]] = 1;
            }
        }
        bitset<501> need;
        for (auto friendship : friendships)
        {
            if (!((learned[friendship[0] - 1] & learned[friendship[1] - 1]).any()))
            {
                need[friendship[0] - 1] = 1;
                need[friendship[1] - 1] = 1;
            }
        }
        int result = 1000000;
        for (int i = 1; i <= n; i++)
        {
            int count = 0;
            for (int j = 0; j < languages.size(); j++)
            {
                if (need[j] && !learned[j][i])
                    count++;
            }
            result = min(result, count);
        }
        return result;
    }
};