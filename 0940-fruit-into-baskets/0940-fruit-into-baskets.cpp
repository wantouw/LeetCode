class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int result = 0;
        int first = fruits[0];
        int second = -1;
        int firstCount = 0;
        int secondCount = 0;
        int left = 0;
        for(int i = 0 ; i < fruits.size() ; i++){
            if(second == -1 && fruits[i]!=first){
                second = fruits[i];
            }
            if(fruits[i] == first){
                firstCount++;
            }
            else if(fruits[i] == second){
                secondCount++;
            }
            else{
                while(firstCount > 0 && secondCount > 0){
                    if(fruits[left] == first){
                        firstCount--;
                    }
                    else{
                        secondCount--;
                    }
                    left++;
                }
                if(firstCount == 0) {
                    first = fruits[i];
                    firstCount++;
                }
                else {
                    second = fruits[i];
                    secondCount++;
                }
            }
            result = max(result, firstCount + secondCount);
        }
        return result;
    }
};