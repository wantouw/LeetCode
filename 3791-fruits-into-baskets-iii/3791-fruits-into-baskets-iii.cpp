class Solution {
public:
    void build(vector<int>& baskets, vector<int>& segmentTree, int left, int right, int index){
        if(left == right){
            segmentTree[index] = baskets[left];
            return;
        }
        int mid = (left + right) / 2;
        build(baskets, segmentTree, left, mid, 2*index+1);
        build(baskets, segmentTree, mid+1, right, 2*index+2);
        segmentTree[index] = max(segmentTree[2*index+1], segmentTree[2*index+2]);
    }
    void search(int fruit, vector<int>& baskets, vector<int>& segmentTree, int left, int right, int index){
        if(left == right){
            if(segmentTree[index] >= fruit){
                segmentTree[index] = 0;
                return;
            }
        }
        if(segmentTree[index] >= fruit){
            int leftMax = segmentTree[2*index+1];
            int rightMax = segmentTree[2*index+2];
            int mid = (left + right) / 2;
            if(leftMax >= fruit){
                search(fruit, baskets, segmentTree, left, mid, 2*index+1);
                segmentTree[index] = max(segmentTree[2*index+2], segmentTree[2*index+1]);
            } 
            else{
                search(fruit, baskets, segmentTree, mid+1, right, 2*index+2);
                segmentTree[index] = max(segmentTree[2*index+2], segmentTree[2*index+1]);
            }
        }
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segmentTree(4*n);
        build(baskets, segmentTree, 0, n-1, 0);
        int sad = 0;
        for(auto fruit: fruits){
            if(segmentTree[0] < fruit) sad++;
            else search(fruit, baskets, segmentTree, 0, n-1, 0);
        }
        return sad;
    }
};