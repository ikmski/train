#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string>

int calc(int** const data, const int num)
{
    return 0;
}

int main(int argc, char* argv[])
{
    if (2 != argc) {
        printf("arg[1] = inputFileName\n");
        return -1;
    }

    char* inputFileName = argv[1];
    FILE* infp;
    FILE* outfp;

    // 入力ファイル
    infp = fopen(inputFileName, "r");
    if (!infp) {
        printf("file not open.\n");
        return -1;
    }

    // ファイルの行数を調べる
    int num = 0;
    fscanf(infp, "%d", &num);
    printf("num = %d\n", num);

    // 領域確保
    int** data = new int*[num];
    for (int i = 0; i < num; ++i) {
        data[i] = new int[num];
    }

    // ファイル入力
    int x, y, t;
    for (int i = 0; i < num-1; ++i) {
        fscanf(infp, "%d,%d,%d", &x,&y,&t);
        data[x-1][y-1] = t;
        data[y-1][x-1] = t;
    }
    fclose(infp); // 入力ファイル

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }


    timeval startTime;     // 開始時刻
    timeval endTime;       // 終了時刻

    // 時間計測開始
    gettimeofday(&startTime, NULL);

    int result =  calc(data, num);
printf("result = %d\n", result);

    // 時間計測終了
    gettimeofday(&endTime, NULL);
    double timeDiff = static_cast<double>(endTime.tv_sec  - startTime.tv_sec);
    double usecDiff = static_cast<double>(endTime.tv_usec - startTime.tv_usec);
    timeDiff += (usecDiff/1000000.0);

    // 出力ファイル
    outfp = fopen("output", "w");
    if (!outfp) {
        printf("file not open.");
        return -1;
    }

    fprintf(outfp, "%4d  %.3f[msec]\n", result, timeDiff*1000.0);
    fclose(outfp); // 出力ファイル

    // 解放
    for (int i = 0; i < num; ++i) {
        delete[] data[i];
    }
    delete[] data;


    return 0;
}

