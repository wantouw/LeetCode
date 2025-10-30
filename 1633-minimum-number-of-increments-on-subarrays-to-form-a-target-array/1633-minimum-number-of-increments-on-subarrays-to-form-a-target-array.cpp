class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int peak = 0;
        int result = 0;
        int valley = 0;
        if (target.size() == 1)
            return target[0];
        bool direction = target[1] >= target[0];
        for (int i = 0; i < target.size(); i++)
        {
            peak = max(target[i], peak);
            if (i > 0 && i < target.size() - 1)
            {
                // if((target[i] >= target[i-1]) != direction)
                if (target[i - 1] >= target[i] && target[i + 1] >= target[i])
                {
                    if (target[i] > valley)
                    {
                        result += target[i] - valley;
                        valley = target[i];
                        result += peak - valley;
                    }
                    else
                    {
                        result += peak - valley;
                        valley = target[i];
                    }
                    peak = target[i];
                }
            }
            // cout << result << endl;
        }
        // if (target[target.size() - 2] > target[target.size() - 1])
        // {
        result += peak - valley;
        // }
        return result;
    }
};