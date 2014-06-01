
#include <stdio.h>
#include <limits.h>
#include "../ProcTime.h"


void radixSort(int* const data, const int size)
{
    int radix = 2;  // 1bit

    // backetとbacketのカウントを用意
    int backet[radix][size];
    int backetCnt[radix];
    for (int i = 0; i < radix; ++i) {
        backetCnt[i] = 0;
    }

    for (int d = 0, logR = 0; d < 32; ++d, logR += 1) {
        // backetに値を入れる
        for (int i = 0; i < size; ++i) {
            int key = (data[i] >> logR) & 0x01;
            backet[key][backetCnt[key]] = data[i];
            ++backetCnt[key];
        }

        // backetを結合
        int index = 0;
        for (int j = 0; j < radix; ++j) {
            for (int k = 0; k < backetCnt[j]; ++k) {
                data[index++] = backet[j][k];
                backet[j][k] = 0;   // backetをからにする
            }
            backetCnt[j] = 0;
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

    radixSort(data, maxSize);

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


