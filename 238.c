/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int i = 0, j = 0;
    int left[numsSize+2];
    int right[numsSize+2];
    
    int *result;
    
    left[0] = 1;
    left[numsSize+1] = 1;
    right[0] = 1;
    right[numsSize+1] = 1;    
    
    result = (int *)calloc(numsSize +2, sizeof(int));
    if (!result) {
        printf("Malloc failed");
        return NULL;
    }
    for (i = 1; i <= numsSize; i++) {
        left[i] = nums[i-1] * left[i-1];
    }
    printf("\n");
    for (i = numsSize; i > 0; i--) {
        right[i] = nums[i-1] * right[i+1];
    }
    printf("\n");
    for (i = 0; i < numsSize; i++) {
        result[i] = left[i] * right[i+2];
    }
    *returnSize = numsSize;
    return result;
}
