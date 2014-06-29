#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int mySqrt(int x)
{
    // 入力値の2進数桁数を調べる
    int i = 0;
    int t = x;
    while (t >>= 1) {
        ++i;
    }

    int a = 0;
    int c = 0;
    int y = 0;
    for (i += i & 1; i >= 0; i -= 2) {
        c = (y << 1 | 1) <= x >> i;
        a = a << 1 | c;
        y = y << 1 | c;
        x -= c * y << i;
        y += c;
//printf("i = %d, a = %o, c = %o, y = %o\n", i, a, c, y);
    }

    return a;
}


int main(int argc, char* argv[])
{
    if (2 != argc) {
        printf("arg[1] = input\n");
        return -1;
    }

    int inputValue = atoi(argv[1]);

    timeval startTime;     // 開始時刻
    timeval endTime;       // 終了時刻


    // 時間計測開始
    gettimeofday(&startTime, NULL);

    int outputValue = mySqrt(inputValue);

    // 時間計測終了
    gettimeofday(&endTime, NULL);
    double timeDiff = static_cast<double>(endTime.tv_sec  - startTime.tv_sec);
    double usecDiff = static_cast<double>(endTime.tv_usec - startTime.tv_usec);
    timeDiff += (usecDiff/1000000.0);

    printf("sqrt(%d) = %d : %.3f[msec]\n", inputValue, outputValue, timeDiff*1000.0);

    return 0;
}

