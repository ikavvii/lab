/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = pow(3, strlen(digits));
    char** result = (char**)calloc(*returnSize * sizeof(char));
    printf("%d", *returnSize);
    return 0;

}