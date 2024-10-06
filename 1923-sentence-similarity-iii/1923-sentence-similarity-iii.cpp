class Solution {
public:
    int frontSimilarity(string sentence1, string sentence2, int minLen) {
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
        int minLen = min(sentence1.length(), sentence2.length());
        int frontValue = frontSimilarity(sentence1, sentence2, minLen);
        int backValue = backSimilarity(sentence1, sentence2, minLen);
        if(sentence1 == sentence2) return true;
        if (frontValue + backValue >= minLen) {
            return true;
        }
        return false;
    }
};