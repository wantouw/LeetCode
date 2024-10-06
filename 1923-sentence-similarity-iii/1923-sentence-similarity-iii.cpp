class Solution {
public:
    // string firstWord(string word){
    //     string result;
    //     int length = word.length();
    //     for(int i = 0; i < length ; i++){
    //         if(word[i] == ' ' ){
    //             break;
    //         }
    //         result+= word[i];
    //     }
    //     return result;
    // }
    // bool isOneWord(string word){
    //     for(char letter: word){
    //         if(letter == ' '){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // string lastWord(string word){
    //     string result;
    //     int length = word.length();
    //     for(int i = length - 1; i >=0 ; i--){
    //         if(word[i] == ' '){
    //             break;
    //         }
    //         result.insert(result.begin(), word[i]);
    //     }
    //     // reverse(result.begin(), result.end());
    //     return result;
    // }
    int frontSimilarity(string sentence1, string sentence2, int minLen) {
        // int minLen = min(sentence1.length(), sentence2.length());
        int similarity = 0;
        int total = 0;
        for (int i = 0; i < minLen; i++) {
            if (sentence1[i] == sentence2[i]) {
                similarity++;
                if ((i == minLen - 1 &&
                     (sentence1[i + 1] == ' ' || sentence2[i + 1] == ' ')) ||
                    (sentence1[i] == ' ' && sentence2[i] == ' ')) {
                    total += similarity;
                    similarity = 0;
                }
            } else {
                break;
            }
        }
        return total;
    }
    int backSimilarity(string sentence1, string sentence2, int minLen) {
        // int minLen = min(sentence1.length(), sentence2.length());
        reverse(sentence1.begin(), sentence1.end());
        reverse(sentence2.begin(), sentence2.end());
        int similarity = 0;
        int total = 0;
        for (int i = 0; i < minLen; i++) {
            if (sentence1[i] == sentence2[i]) {
                similarity++;
                if ((i == minLen - 1 &&
                     (sentence1[i + 1] == ' ' || sentence2[i + 1] == ' ')) ||
                    (sentence1[i] == ' ' && sentence2[i] == ' ')) {
                    total += similarity;
                    similarity = 0;
                }
            } else {
                break;
            }
        }
        return total;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // string first1 = firstWord(sentence1), first2 = firstWord(sentence2);
        // string last1 = lastWord(sentence1), last2 = lastWord(sentence2);
        // bool isOne1 = isOneWord(sentence1), isOne2 = isOneWord(sentence2);
        // cout << first1 << ' ' << last1 << ' ' << isOne1 << endl;
        // cout << first2 << ' ' << last2 << ' ' << isOne2 << endl;
        int minLen = min(sentence1.length(), sentence2.length());
        int frontValue = frontSimilarity(sentence1, sentence2, minLen);
        int backValue = backSimilarity(sentence1, sentence2, minLen);
        // cout << "front: " << frontValue << "back: " << backValue << endl;
        if(sentence1 == sentence2) return true;
        if (frontValue + backValue >= minLen) {
            return true;
        }
        return false;
    }
};