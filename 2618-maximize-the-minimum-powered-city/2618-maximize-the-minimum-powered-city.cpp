class Solution {
public:
    bool possible(vector<int> stations, long long mid, int r, int k)
    {
        long long power = reduce(stations.begin(), stations.begin() + r, 0LL);
        long long need = 0;
        for (int i = 0; i < stations.size(); i++)
        {
            if (i > r)
            {
                power -= stations[max(0, i - r - 1)];
            }
            if (i + r < stations.size())
            {
                power += stations[i + r];
            }
            if (power < mid)
            {
                need = mid - power;
                if (need > k)
                    return false;
                k -= need;
                int pos = min((long long)stations.size() - 1, (long long)i + r);
                // cout << stations[pos] << endl;
                stations[pos] += need;
                power += need;
            }
        }
        return true;
    }

    long long maxPower(vector<int> &stations, int r, int k)
    {

        long long high = reduce(stations.begin(), stations.end(), 0LL) + k;
        long long low = 0, ans = 0;

        while (low <= high)
        {
            long long mid = (long long) (high + low) / 2;
            // cout << "low: " << low << ", high: " << high << endl;
            if (possible(stations, mid, r, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            // if (low == 5)
            // 	break;
        }
        return ans;
    }
};