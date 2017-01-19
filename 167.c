#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int val;
    int idx;
    struct node *next;
} Node;

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numbersSize, int target, int* returnSize) {
    Node **table, *tmp, *node;
    int *result;
    int i, j;
    int index;
    int found = 0;
    
    table = (Node *) calloc(numbersSize, sizeof(Node *));
    if (!table) {
        printf("malloc failed\n");
        return NULL;
    }
    result = (int *) calloc(2, sizeof(int));
    if (!result) {
        printf("malloc failed\n");
        return NULL;
    }   

    for (i = 0; (i < numbersSize) && !found; i++) {
       
        index = nums[i]%numbersSize;
        tmp = *(table + index);

        while (tmp) {

            if ((tmp->val)  == nums[i]) {
                 result[0] =   tmp->idx +1;
                 result[1] =   i +1;
                 found = 1;
                 break;
            }
            tmp = tmp->next;
        }
        if (!found) {

            index = (target-nums[i])%numbersSize;
            tmp = *(table + index);
            node = (Node *) calloc(1, sizeof(Node));
            node->val = target-nums[i];
            node->next = tmp;
            node->idx = i;
        
            *(table + index) = node;
           
        } 
    }
    if (found)
        *returnSize = 2;
    else
        *returnSize = 0;
    
    return result;
}
