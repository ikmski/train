#include <stdio.h>
#include <sys/time.h>
#include <time.h>

timeval start_time;     //!< 開始時刻
timeval end_time;       //!< 終了時刻

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
    unsigned long base = 0x7fffffffffffffff;

    for (int i = 0; i < 63; ++i) {

        long a = data - base;
        if (a >= 0) {
            result = count(a) + count(base);
            break;
        }
        base = base >> 1;
    }

    return result;
}

void procStart()
{
     gettimeofday(&start_time, NULL);
}

double procEnd()
{
    gettimeofday(&end_time, NULL);
    double time_diff = static_cast<double>(end_time.tv_sec  - start_time.tv_sec);
    double usec_diff = static_cast<double>(end_time.tv_usec - start_time.tv_usec);
    time_diff += (usec_diff/1000000.0);
    return time_diff * 1000.0;
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
        fscanf(fp, "%ld", &buf);
        data[index] = buf;
        buf = 0;
    }

    fclose(fp);

    // 出力ファイル
    fp = fopen("./output", "w");
    if (!fp) {
        printf("file not open.");
        return -1;
    }

    for (int i = 0; i < num; ++i) {

        procStart();

        int result =  max(data[i]);

        double procTime = procEnd();

        fprintf(fp, "Case #%03d: %6d %.3f[msec]\n", i+1, result, procTime);
    }

    fclose(fp);
    delete[] data;

    return 0;
}
