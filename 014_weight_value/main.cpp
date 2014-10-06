#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string>

int calc(int** const data, const int num)
{

    return 1;
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
        data[i] = new int[2];
    }

    // ファイル入力
    for (int i = 0; i < num; ++i) {
        fscanf(infp, "%d,%d", &data[i][0], &data[i][1]);
printf("%d %d\n", data[i][0], data[i][1]);
    }
    fclose(infp); // 入力ファイル

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
    std::string inputPath(inputFileName);
    int l = inputPath.length();
    std::string outputFileName(inputPath.substr(l-6));
    std::string indexStr(inputPath.substr(l-2));

    outfp = fopen(outputFileName.c_str(), "w");
    if (!outfp) {
        printf("file not open.");
        return -1;
    }

    fprintf(outfp, "Case #%s: %4d  %.3f[msec]\n", indexStr.c_str(), result, timeDiff*1000.0);
    printf("Case #%s: %4d  %.3f[msec]\n", indexStr.c_str(), result, timeDiff*1000.0);

    // 解放
    for (int i = 0; i < 2; ++i) {
        delete[] data[i];
    }
    delete[] data;


    return 0;
}

