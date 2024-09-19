/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int** dp;
// int** flag;
// int xorr(int current, int final, int* array, int arrSize) {
//     int distortedFinal = ((arrSize-1)-final);
//     if (current == final) {
//         return array[current];
//     }
//     // printf("final %d current %d\n", final, current);
//     if (dp[current][distortedFinal] != 0) {
//         return dp[current][distortedFinal];
//     }
//     // flag[current][final] = 1;
//     return dp[current][distortedFinal] = array[current] ^ xorr(current + 1, final, array, arrSize);
// }

int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize,
                int* queriesColSize, int* returnSize) {
    int* dp = (int*)malloc(arrSize * sizeof(int)); 

    // Allocate memory for each row, creating the triangular structure
    for (int i = 0; i < arrSize; i++) {
        if (i==0) dp[i] = arr[i];
        else dp[i] = arr[i] ^ dp[i-1]; 
        // printf("row ke-%d %d\n", i , dp[i][0]);

        // calloc initializes memory to zero, and arrSize - i is the number of elements in each row
    }
    // flag = (int**)malloc(
    //     arrSize * sizeof(int*)); 

    // for (int i = 0; i < arrSize; i++) {
    //     flag[i] =
    //         (int*)calloc(arrSize, sizeof(int)); // Allocate memory for each row
    // }
    int* result = (int*)malloc(sizeof(int) * (queriesSize + 5));
    for (int i = 0; i < queriesSize; i++) {
        if(queries[i][0] == 0){
            result[i] = dp[queries[i][1]];
        }
        else{
            result[i] = dp[queries[i][1]] ^ dp[queries[i][0] - 1];
        }
        // printf("%d %d\n", queries[i][0], queries[i][1]);
        // printf("%d %d\n", result[i], xorr(queries[i][0], queries[i][1], arr, arrSize));
    }
    *returnSize = queriesSize;
    return result;
}