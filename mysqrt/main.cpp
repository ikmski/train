#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

const int DECIMAL_BITS = 16;

int mySqrt(int x)
{
    int a = 0;
    int c = 0;
    int y = 0;
    for (int i = 30; i >= 0; i -= 2) {
        c = (y << 1 | 1) <= x >> i;
        a = a << 1 | c;
        y = y << 1 | c;
        x -= c * y << i;
        y += c;
    }

    return a << (DECIMAL_BITS/2);
}

int intToFixd(int x)
{
    return x << DECIMAL_BITS;
}

double fixedToDouble(int x)
{
    double result = static_cast<double>(x >> DECIMAL_BITS);
    double y = 0.5;
    for (int i = DECIMAL_BITS-1; i >= 0; --i) {
        result += ((x >> i) & 0x1) * y;
        y *= 0.5;
    }

    return result;
}

int main(int argc, char* argv[])
{
    if (2 != argc) {
        printf("arg[1] = input\n");
        return -1;
    }

    int input = atoi(argv[1]);

    timeval startTime;     // 開始時刻
    timeval endTime;       // 終了時刻

    gettimeofday(&startTime, NULL); // 時間計測開始

    int result = mySqrt(intToFixd(input));

    gettimeofday(&endTime, NULL);   // 時間計測終了
    double timeDiff = static_cast<double>(endTime.tv_sec  - startTime.tv_sec);
    double usecDiff = static_cast<double>(endTime.tv_usec - startTime.tv_usec);
    timeDiff += (usecDiff/1000000.0);

    double output = fixedToDouble(result);
    printf("sqrt(%d) = %f : %.3f[msec]\n", input, output, timeDiff*1000.0);

    return 0;
}

