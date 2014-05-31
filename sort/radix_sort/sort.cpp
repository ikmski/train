
#include <stdio.h>
#include <limits.h>
#include "../ProcTime.h"


void radixSort(int* const data, const int size)
{
    // backetとbacketのカウントを用意
    int backet[256][256];
    int backetCnt[256];
    for (int i = 0; i < 256; ++i) {
        backetCnt[i] = 0;
    }

    for (int d = 0, logR = 0; d < 4; ++d, logR += 8) {
        // backetに値を入れる
        for (int i = 0; i < size; ++i) {
            int key = (data[i] >> logR) & 255;  // 256進のd桁目だけを取り出す
            backet[key][backetCnt[key]] = data[i];
            ++backetCnt[key];
        }

        // backetを結合
        int index = 0;
        for (int j = 0; j < 256; ++j) {
            for (int k = 0; backetCnt[j]; ++k) {
                data[index++] = backet[j][k];
            }
        }

        // backetを空にする
        for (int i = 0; i < 256; ++i) {
            for (int j = 0; j < INT_MAX; ++j) {
                backet[i][j] = 0;
            }
            backetCnt[i] = 0;
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


