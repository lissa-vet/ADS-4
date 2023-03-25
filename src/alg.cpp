// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    int left_border = 0;
    int right_border = size - 1;
    int count = 0;
    int mid;
    while (left_border != right_border) {
        mid = (left_border + right_border) / 2;
        if (arr[mid] == value) {
            count++;
            int mid1 = mid - 1;
            while (arr[mid1] == value) {
                count++;
                mid1--;
            }
            int mid2 = mid + 1;
            while (arr[mid2] == value) {
                count++;
                mid2++;
            }
            left_border = right_border;
        }
        if (arr[mid] > value)
            right_border = mid;
        if (arr[mid] < value)
            left_border = mid + 1;
    }
    return count;
}

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int elem = value - arr[i];
        count += cbinsearch(&arr[i+1], len - i - 1, elem);
    }
    return count;
}
