class Solution {
public:
    void tree(string curr, int max, vector<int>& result){
        int value = stoi(curr);
        if(value > max || value == 0) return;
        cout << value << endl;
        if(value!=0) result.push_back(value);
        tree(curr + "0", max, result);
        tree(curr + "1", max, result);
        tree(curr + '2', max, result);
        tree(curr + '3', max, result);
        tree(curr + '4', max, result);
        tree(curr + '5', max, result);
        tree(curr + '6', max, result);
        tree(curr + '7', max, result);
        tree(curr + '8', max, result);
        tree(curr + '9', max, result);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        tree("1", n, result);
        tree("2", n, result);
        tree("3", n, result);
        tree("4", n, result);
        tree("5", n, result);
        tree("6", n, result);
        tree("7", n, result);
        tree("8", n, result);
        tree("9", n, result);
        return result;
    }
};