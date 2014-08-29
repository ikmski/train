#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <limits.h>

void swap(const char* const src, char* const dst)
{
    int size = strlen(src);

    for (int i = 0; i < size; ++i) {
        dst[i] = src[size-i-1];
    }
    dst[size] = '\0';
    //printf("%s <=> %s\n", src, dst);
}

void dec2bin(const unsigned long src, char* const dst)
{
    unsigned long tmp = src;
    int digit = 0;
    while (tmp > 0) {
        tmp >>= 1;
        ++digit;
    }
    for (int i = 0; i < digit; ++i) {
        int bin = (src >> (digit-1-i)) & 0x01;
        char buf[1];
        sprintf(buf, "%d", bin);
        dst[i] = buf[0];
    }
    dst[digit] = '\0';
}

unsigned long calc(int findNum=1)
{
    unsigned long result = 0;

    char dec[128];
    char decSwap[128];
    char bin[128];
    char binSwap[128];
    char oct[128];
    char octSwap[128];

    int cnt = 0;
    unsigned long i = 9;
    while (1) {
        ++i;
        if (i == ULONG_MAX) break;

        if (i%1000000 == 0) {
            printf("i = %d\n",i);
        }

        sprintf(dec, "%lu", i);
        swap(dec, decSwap);
        if (0 != strcmp(dec, decSwap)) continue;

        sprintf(oct, "%lo", i);
        swap(oct, octSwap);
        if (0 != strcmp(oct, octSwap)) continue;

        dec2bin(i, bin);
        swap(bin, binSwap);
        if (0 != strcmp(bin, binSwap)) continue;

        result = i;
        printf("%s, %s, %s\n", dec, oct, bin);
        ++cnt;
        if (cnt >= findNum) {
            break;
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    timeval startTime;     // 開始時刻
    timeval endTime;       // 終了時刻

    // 時間計測開始
    gettimeofday(&startTime, NULL);

    unsigned long result =  calc(1);

    // 時間計測終了
    gettimeofday(&endTime, NULL);
    double timeDiff = static_cast<double>(endTime.tv_sec  - startTime.tv_sec);
    double usecDiff = static_cast<double>(endTime.tv_usec - startTime.tv_usec);
    timeDiff += (usecDiff/1000000.0);

    printf("%lu  %.3f[msec]\n", result, timeDiff*1000.0);

    return 0;
}

