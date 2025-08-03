class Solution {
public:
    int minTraversal(int left, int right, int start){
        return min(abs(start - left) + abs(right - left), 
            abs(start - right) + abs(right - left));
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0, sum = 0, result = 0;
        for(int right = 0 ; right < fruits.size() ; right++){
            sum+=fruits[right][1];
            while(left<=right && minTraversal(fruits[left][0], fruits[right][0], startPos) > k){
                sum-=fruits[left++][1];
                // left++;
            }
            result = max(sum, result);
        }
        return result;
    }
};