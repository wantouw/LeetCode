class Solution {
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        char curr = colors[0];
        int minimum = -1;
        int result = 0;
        int count = 0;
        for (int i = 0; i < colors.length(); i++)
        {
            if (colors[i] != curr)
            {
                result -= minimum;
                curr = colors[i];
                minimum = -1;
                count = 0;
            }
            minimum = max(minimum, neededTime[i]);
            count++;
            result += neededTime[i];
        }

        return result - minimum;
    }
};