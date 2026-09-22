int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 1; i <= numsSize + 1; i++) {
        int found = 0;

        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == i) {
                found = 1;
                break;
            }
        }

        if (found == 0)
            return i;
    }

    return 1;
}