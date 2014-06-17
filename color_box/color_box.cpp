#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int getMaxmum(
              const int numRed,
              const int numBlue,
              const int onlyRed,
              const int onlyBlue,
              const int bothColors)
{
    int result = 0;
    return result;
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

    // 出力ファイル
    outfp = fopen("./output", "w");
    if (!outfp) {
        printf("file not open.");
        return -1;
    }

    int num = 0;
    fscanf(infp, "%d", &num);
    printf("num = %d\n", num);

    int numRed     = 0;
    int numBlue    = 0;
    int onlyRed    = 0;
    int onlyBlue   = 0;
    int bothColors = 0;

    timeval startTime;     // 開始時刻
    timeval endTime;       // 終了時刻

    for (int index = 0; index < num; ++index) {
        fscanf(infp, "%d,%d,%d,%d,%d", &numRed, &numBlue, &onlyRed, &onlyBlue, &bothColors);

        // 時間計測開始
        gettimeofday(&startTime, NULL);

        int result =  getMaxmum(numRed, numBlue, onlyRed, onlyBlue, bothColors);

        // 時間計測終了
        gettimeofday(&endTime, NULL);
        double timeDiff = static_cast<double>(endTime.tv_sec  - startTime.tv_sec);
        double usecDiff = static_cast<double>(endTime.tv_usec - startTime.tv_usec);
        timeDiff += (usecDiff/1000000.0);

        fprintf(outfp, "Case #%03d: %4d  %.3f[msec]\n", index+1, result, timeDiff*1000.0);
    }

    fclose(infp); // 入力ファイル
    fclose(outfp); // 出力ファイル

    return 0;
}

