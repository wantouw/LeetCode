class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int size = fruits.size();
        int firstMax = 0;
        int maxFruit = 0;
        for(int i = 0 ; i < size ; i++){
            firstMax+=fruits[i][i];
            fruits[i][i] = 0;
        }
        int secondMax = fruits[0][size-1];
        for(int i = 1 ; i <= size / 2 ; i++){
            if(i == size / 2 && size % 2 == 0) break;
            if(i == 1){
                fruits[i][size-1]+=fruits[0][size-1];
                fruits[i][size-2]+=fruits[0][size-1];
                continue;
            }
            for(int j = 0 ; j <= i ; j++){
                int maxValue = 0;
                int right = size - j;
                int mid = size - j - 1;
                int left = size - j - 2;
                // cout << "curr: " << fruits[i][size - j - 1] << endl;
                if(right < size) maxValue = max(maxValue, fruits[i-1][right]);
                // if(right < size) cout << "right: " << fruits[i-1][right];
                if(mid > size - i - 1) maxValue = max(maxValue, fruits[i-1][mid]);
                // if(mid > size - i - 1) cout << " mid: " << fruits[i-1][mid];
                if(left > size - i - 1) maxValue = max(maxValue, fruits[i-1][left]);
                // if(left > size - i - 1) cout << " left: " << fruits[i-1][left];
                fruits[i][size - j - 1] += maxValue; 
                // cout << endl;
            }
        }
        int midSize = size / 2 - 1;
        if(size % 2 == 1) midSize++; 
        for(int i = 1 ; i < size / 2 ; i++){
            for(int j = 0 ; j <= size / 2 - i ; j++){
                int maxValue = 0;
                int right = size - j;
                int mid = size - j - 1;
                int left = size - j - 2;
                // cout << "curr: " << fruits[midSize + i][size - j - 1] << endl;
                if(right < size) maxValue = max(maxValue, fruits[midSize + i-1][right]);
                // if(right < size) cout << "right: " << fruits[midSize + i-1][right];
                maxValue = max(maxValue, fruits[midSize + i-1][mid]);
                // cout << " mid: " << fruits[midSize + i-1][mid];
                maxValue = max(maxValue, fruits[midSize + i-1][left]);
                // cout << " left: " << fruits[midSize + i-1][left];
                fruits[midSize + i][size - j - 1] += maxValue; 
                // cout << endl;
            }
        }
        secondMax = max(fruits[size-2][size-2], fruits[size-2][size-1]);
        // cout << "secondMax: " << secondMax << endl;
        for(int i = 0 ; i < size ; i++){
            fruits[i][i] = 0;
        }
        int thirdMax = fruits[size-1][0];
        for(int i = 1 ; i <= size / 2 ; i++){
            if(i == size / 2 && size % 2 == 0) break;
            if(i == 1){
                fruits[size-1][i]+=fruits[size-1][0];
                fruits[size-2][i]+=fruits[size-1][0];
                continue;
            }
            for(int j = 0 ; j <= i ; j++){
                int maxValue = 0;
                int right = size - j;
                int mid = size - j - 1;
                int left = size - j - 2;
                // cout << "curr: " << fruits[i][size - j - 1] << endl;
                if(right < size) maxValue = max(maxValue, fruits[right][i-1]);
                // if(right < size) cout << "right: " << fruits[right][i-1];
                if(mid > size - i - 1) maxValue = max(maxValue, fruits[mid][i-1]);
                // if(mid > size - i - 1) cout << " mid: " << fruits[mid][i-1];
                if(left > size - i - 1) maxValue = max(maxValue, fruits[left][i-1]);
                // if(left > size - i - 1) cout << " left: " << fruits[left][i-1];
                fruits[size-j-1][i] += maxValue; 
                // cout << endl;
            }
        }
        for(int i = 1 ; i < size / 2 ; i++){
            for(int j = 0 ; j <= size / 2 - i ; j++){
                int maxValue = 0;
                int right = size - j;
                int mid = size - j - 1;
                int left = size - j - 2;
                // cout << "curr: " << fruits[size - j - 1][midSize + i] << endl;
                if(right < size) maxValue = max(maxValue, fruits[right][midSize + i-1]);
                // if(right < size) cout << "right: " << fruits[right][midSize + i-1];
                maxValue = max(maxValue, fruits[mid][midSize + i-1]);
                // cout << " mid: " << fruits[mid][midSize + i-1];
                maxValue = max(maxValue, fruits[left][midSize + i-1]);
                // cout << " left: " << fruits[left][midSize + i-1];
                fruits[mid][midSize + i] += maxValue; 
                // cout << endl;
            }
        }
        thirdMax = max(fruits[size-2][size-2], fruits[size-1][size-2]);
        // cout << firstMax << " " << secondMax << " " << thirdMax << endl;
        return firstMax + secondMax + thirdMax;
    }
};