class Solution {
public:
    int charToNum(char c){
        if(c >= '1' && c <= '9'){
            return c - '0';
        }
        return 0;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // cout << charToNum('1');
        int SIZE = 9;
        unordered_set<int> vertical;
        unordered_set<int> horizontal;
        for(int i = 0 ; i < SIZE ; i++){
            for(int j = 0 ; j < SIZE ; j++){
                int horizontalNum = charToNum(board[i][j]);
                int verticalNum = charToNum(board[j][i]);
                if(vertical.find(verticalNum)!= vertical.end() || 
                    horizontal.find(horizontalNum) != horizontal.end()){
                    return false;
                }
                if(horizontalNum != 0) horizontal.insert(horizontalNum);
                if(verticalNum != 0) vertical.insert(verticalNum);
            }
            horizontal.clear();
            vertical.clear();
        }
        for(int i = 0 ; i < SIZE ; i+=3){
            for(int j = 0 ; j < SIZE ; j+=3){
                for(int k = 0 ; k < 3 ; k++){
                    for(int l = 0 ; l < 3 ; l++){
                        int number = charToNum(board[i+k][j+l]);
                        if(horizontal.find(number) != horizontal.end()){
                            return false;
                        }
                        if(number != 0) horizontal.insert(number);
                    }
                }
                horizontal.clear();
            }
        }
        return true;
    }
};