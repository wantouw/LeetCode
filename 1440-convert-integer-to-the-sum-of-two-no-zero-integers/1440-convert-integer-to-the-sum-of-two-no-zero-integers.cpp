class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
      vector<int> result;
      result.push_back(0);
      result.push_back(0);
      bool flag = false;
      int size = 0;
      for(int i = 5; i >= 1 ; i--){
        int digit = n % (int) pow(10, i) / (int) pow(10, i - 1);
        if(!flag && digit == 0) continue;
        // System.out.println("i: " + i + ", digit: " + digit);
        if(digit % 2 == 0){
        //   else {
            result[0] += (digit / 2) * (int) pow(10, i - 1);
            result[1] += (digit / 2) * (int) pow(10, i - 1);
        //   }
        }
        else {
          result[0] += (digit / 2) * (int) pow(10, i - 1);
          result[1] += (digit / 2) * (int) pow(10, i - 1);
          result[0] += 5 * (int) pow(10, i - 2);
          result[1] += 5 * (int) pow(10, i - 2);
          if(i == 1) result[0]++;
        }
        flag = true;
        if(size == 0) size = i;
        for(int i = 1 ; i <= size - 1 ; i++){
            int firstDigit = result[0] % (int) pow(10, i) / (int) pow(10, i - 1);
            int secondDigit = result[1] % (int) pow(10, i) / (int) pow(10, i - 1);
            if(firstDigit == 0 || secondDigit == 0){
                result[0] += 1 * (int) pow(10, i - 1);
                result[1] -= 1 * (int) pow(10, i - 1);
            }
        }
      }
      return result;
    }
};