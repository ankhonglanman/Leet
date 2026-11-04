int minMoves(int* nums, int numsSize) {
    int max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (max < nums[i]) max = nums[i];
    }

    int minMoves = 0;
    for(int i = 0; i < numsSize; i++) {
        minMoves += max - nums[i];
    }

    return minMoves;
}