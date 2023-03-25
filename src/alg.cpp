// Copyright 2021 NNTU-CS

void sort(int* arr, int len) {
    int elem;
    bool flag;
    for (int i = len - 1; i > 0; i--) {
        flag = true;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                elem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = elem;
                flag = false;
            }
        }
        if (flag) {
            break;
        }
    }
}

int binsearch(int* arr, int k, int len, int elem) {
    int mid, side;
    int count = 0;
    int i = k; int j = len;
    while (i < j - 1) {
        mid = (i + j) / 2;
        if (arr[mid] > elem) {
            j = mid;
        } else if (arr[mid] < elem) {
            i = mid;
        } else {
            count++;
            side = mid + 1;
            while ((arr[side] == elem) && (side < j)) {
                count++;
                side++;
            }
            side = mid - 1;
            while ((arr[side] == elem) && (side > i)) {
                count++;
                side--;
            }
            break;
        }
    }
    return count;
}

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = len - 1; i >= ; i--) {
        if (arr[i] <= value) {
            for (int j = i + 1; j < len; j++) {
                if (arr[i] + arr[j] == value) {
                    count++;
                }
            }
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    sort(arr, len);
    int count = 0;
    int elem;
    for (int k = 0; k < len - 1; k++) {
        elem = value - arr[k];
        count += binsearch(arr, k, len, elem);
    }
    return count;
}
