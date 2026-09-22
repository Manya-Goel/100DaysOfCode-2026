int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* answer = malloc(temperaturesSize * sizeof(int));

    *returnSize = temperaturesSize;

    for (int i = 0; i < temperaturesSize; i++) {
        answer[i] = 0;

        for (int j = i + 1; j < temperaturesSize; j++) {
            if (temperatures[j] > temperatures[i]) {
                answer[i] = j - i;
                break;
            }
        }
    }

    return answer;
}