// Copyright 2021 NNTU-CS
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

int cbinsearch(int* arr, int k, int len, int elem) {
    int mid, side;
    int count = 0;
    int i = k, j = len;
    while (i < j - 1) {
        mid = (i + j) / 2;
        if (arr[mid] + arr[i] > elem) j = mid;
        else if (arr[mid] + arr[i] < elem) {
            i = mid;
        } else if (arr[i] + arr[mid] == elem) {
            count++;
            side = mid + 1;
            while ((arr[side] + arr[i] == elem) && (side < j)) {
                count++;
                side++;
            }
            side = mid - 1;
            while ((arr[side] + arr[i] == elem) && (side > i)) {
                count++;
                side--;
            }
            break;
          }  
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        count += cbinsearch(arr, i, len, value);
    }
    return count;
}
