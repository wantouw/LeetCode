class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // cout << timePoints[0];
        vector<int> minutes;
        for (auto it = timePoints.begin(); it != timePoints.end(); it++) {
            int minute = (((*it)[0] - '0') * 60 * 10) +
                         (((*it)[1] - '0') * 60) + (((*it)[3] - '0') * 10) +
                         ((*it)[4] - '0');
            // cout << minute << ' ' << *it << '\n';
            minutes.push_back(minute);
        }
        sort(minutes.begin(), minutes.end());
        // for(auto i = minutes.begin();i!=minutes.end();i++){
            // cout << *i << ' ';
        // }
        int length = minutes.size();
        int smallestDiff = 10000;
        for (int i = 0; i < length; i++) {
            int temp;
            if (i == 0) {
                if (minutes[i] < minutes[length - 1]) {
                    temp = minutes[i] + 1440 - minutes[length - 1];

                } else {
                    temp = minutes[i] - minutes[length - 1];
                }
            }
            else{
                temp = minutes[i] - minutes[i - 1];
            }
            if (temp < smallestDiff) {
                smallestDiff = temp;
            }
        }
        return smallestDiff;
    }
};