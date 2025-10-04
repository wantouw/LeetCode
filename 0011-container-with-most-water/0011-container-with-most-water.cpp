class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int result = 0, curr = 0;
        while(left < right){
            int minHeight = min(height[left], height[right]);
            curr = minHeight * (right - left);
            result = max(result, curr);
            if(minHeight == height[left]) left++;
            else right--;
        }
        return result;
    }
};