class Solution {
public:
    void tree(int curr, int max, vector<int>& result) {
        if (curr > max)
            return;
        if (curr != 0) {
            result.push_back(curr);
            tree(curr * 10, max, result);
        }
        tree(curr * 10 + 1, max, result);
        tree(curr * 10 + 2, max, result);
        tree(curr * 10 + 3, max, result);
        tree(curr * 10 + 4, max, result);
        tree(curr * 10 + 5, max, result);
        tree(curr * 10 + 6, max, result);
        tree(curr * 10 + 7, max, result);
        tree(curr * 10 + 8, max, result);
        tree(curr * 10 + 9, max, result);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        tree(0, n, result);
        return result;
    }
};