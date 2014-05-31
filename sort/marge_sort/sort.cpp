
#include <stdio.h>
#include "../ProcTime.h"


void _margeSort(int* data, int* tmp, int min, int max);
void marge(int* data, int* tmp, int min, int mid, int max);

void margeSort(int* const data, const int size)
{
    int tmp[size];  // 作業領域
    _margeSort(data, tmp, 0, size-1);

    return;
}

void _margeSort(int* data, int* tmp, int min, int max)
{
    if (min < max) {
        int mid = (min + max) / 2;
        _margeSort(data, tmp, min, mid);
        _margeSort(data, tmp, mid+1, max);
        marge(data, tmp, min, mid, max);
    }

    return;
}

void marge(int* data, int* tmp, int min, int mid, int max)
{
    for (int i = min; i <= mid; ++i) {
        tmp[i] = data[i];   // 左半分を作業領域にコピー
    }
    for (int i = mid+1, j = max; i <= max; ++i, --j) {
        tmp[i] = data[j];   // 右半分は逆順にコピー
    }

    int i = min;    // 左側要素の最少値の位置
    int j = max;    // 右側要素の最少値の位置
    for (int k = min; k <= max; ++k) {
        if (tmp[i] < tmp[j]) {
            data[k] = tmp[i];
            ++i;
        }
        else {
            data[k] = tmp[j];
            --j;
        }
    }

    return;
}


int main(int argc, char* argv[])
{
    if (2 != argc) {
        printf("arg[1] = fileName\n");
        return -1;
    }

    char* fileName = argv[1];

    FILE* fp;
    int buf = 0;
    int data[1000000];

    fp = fopen(fileName, "r");
    if (!fp) {
        printf("file not open.\n");
        return -1;
    }

    int index = 0;
    while (EOF != fscanf(fp, "%d", &buf)) {
        data[index] = buf;
        buf = 0;
        ++index;
    }

    fclose(fp);

    int maxSize = index;

    ProcTime* procTime = new ProcTime();
    procTime->start();

    margeSort(data, maxSize);

    procTime->end();

    fp = fopen("./output.csv", "w");
    if (!fp) {
        printf("file not open.");
        return -1;
    }
    for (int i = 0; i < maxSize; ++i) {
        fprintf(fp, "%d\n", data[i]);
    }
    fclose(fp);

    return 0;
}


