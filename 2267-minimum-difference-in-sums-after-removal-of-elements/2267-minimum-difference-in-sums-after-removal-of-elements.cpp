class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int size = nums.size();
        int k = size / 3;
        vector<long long> leftSums(size), rightSums(size);
        priority_queue<int> maxLeftHeap;
        priority_queue<int, vector<int>, greater<int>> minRightHeap;
        long long leftSum = 0;
        long long rightSum = 0;
        for(int i = 0 ; i < k ; i++){
            maxLeftHeap.push(nums[i]);
            leftSum += nums[i];
        }
        leftSums[k-1] = leftSum;
        for(int i = k ; i < size - k ; i++){
            if(nums[i] < maxLeftHeap.top()){
                leftSum -= maxLeftHeap.top();
                maxLeftHeap.pop();
                leftSum += nums[i];
                maxLeftHeap.push(nums[i]);
            }
            leftSums[i] = leftSum;
        }
        for(int i = size - k ; i < size ; i++){
            minRightHeap.push(nums[i]);
            rightSum+=nums[i];
        }
        rightSums[size - k] = rightSum;
        for(int i = size - k - 1;  i >= k ; i--){
            if(nums[i] > minRightHeap.top()){
                rightSum -= minRightHeap.top();
                minRightHeap.pop();
                rightSum += nums[i];
                minRightHeap.push(nums[i]);
            }
            rightSums[i] = rightSum;
        }
        long long res = leftSums[k-1] - rightSums[k];
        for(int i = k - 1 ; i < size - k ; i++){
            res = min(res, leftSums[i] - rightSums[i+1]);
        }
        return res;
    }
};