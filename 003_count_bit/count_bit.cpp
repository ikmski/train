#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int count(const unsigned long data)
{
    int result = 0;
    for (int i = 0; i < 64; ++i) {
        result += (data >> i) & 0x01;
    }

    return result;
}

int max(const unsigned long data)
{
    int result = 0;
    unsigned long a = 0x7fffffffffffffff;

    for (int i = 0; i < 63; ++i) {

        long b = data - a;
        if (b >= 0) {
            result = count(a) + count(b);
            break;
        }
        a = a >> 1;
    }

    return result;
}

int main(int argc, char* argv[])
{
    if (2 != argc) {
        printf("arg[1] = fileName\n");
        return -1;
    }

    char* fileName = argv[1];
    FILE* fp;

    // 入力ファイル
    fp = fopen(fileName, "r");
    if (!fp) {
        printf("file not open.\n");
        return -1;
    }

    int num = 0;
    fscanf(fp, "%d", &num);
    printf("num = %d\n", num);

    unsigned long* data = new unsigned long[num];
    unsigned long  buf = 0;

    for (int index = 0; index < num; ++index) {
        fscanf(fp, "%lu", &buf);
        data[index] = buf;
        buf = 0;
    }

    fclose(fp); // 入力ファイル

    // 出力ファイル
    fp = fopen("./output", "w");
    if (!fp) {
        printf("file not open.");
        return -1;
    }

    for (int i = 0; i < num; ++i) {

        timeval startTime;     //!< 開始時刻
        timeval endTime;       //!< 終了時刻

        // 時間計測開始
        gettimeofday(&startTime, NULL);

        int result =  max(data[i]);

        // 時間計測終了
        gettimeofday(&endTime, NULL);
        double timeDiff = static_cast<double>(endTime.tv_sec  - startTime.tv_sec);
        double usecDiff = static_cast<double>(endTime.tv_usec - startTime.tv_usec);
        timeDiff += (usecDiff/1000000.0);

        fprintf(fp, "Case #%03d: %4d  %.3f[msec]\n", i+1, result, timeDiff*1000.0);
    }

    fclose(fp); // 出力ファイル
    delete[] data;

    return 0;
}

