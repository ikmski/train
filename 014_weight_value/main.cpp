#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string>
#include <algorithm>

const int MAX_W = 10;

int dfs(int* ws, int* ps, int** dp, int num, int n, int w)
{
    if (w > MAX_W) return -1;
    if (n >= num) return 0;
    if (dp[n][w] >= 0) return dp[n][w];

    if (w < ws[n]) {
        dp[n][w] = dfs(ws, ps, dp, num, n+1, w);
    }
    else {
        dp[n][w] = std::max(dfs(ws, ps, dp, num, n+1, w), dfs(ws, ps, dp, num, n+1, w-ws[n]) + ps[n]);
    }
        printf("%d, %d, %d\n", n, w, dp[n][w]);
    return dp[n][w];
}

int calc(int* const ws, int* const ps, const int num)
{
    int result = 0;

    int** dp = new int*[num+1];
    for (int i = 0; i < num+1; ++i) {
        dp[i] = new int[MAX_W+1];
    }

    for (int i = 0; i < num+1; ++i) {
        for (int j = 0; j < MAX_W+1; ++j) {
            dp[i][j] = -1;
        }
    }

    result = dfs(ws, ps, dp, num, 0, 10);

    for (int i = 0; i < num+1; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

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

    // ファイルの行数を調べる
    int num = 0;
    fscanf(infp, "%d", &num);
    printf("num = %d\n", num);

    // 領域確保
    int* ws = new int[num];
    int* ps = new int[num];

    // ファイル入力
    for (int i = 0; i < num; ++i) {
        fscanf(infp, "%d,%d", &ws[i], &ps[i]);
printf("%d %d\n", ws[i], ps[i]);
    }
    fclose(infp); // 入力ファイル

    timeval startTime;     // 開始時刻
    timeval endTime;       // 終了時刻

    // 時間計測開始
    gettimeofday(&startTime, NULL);

    int result =  calc(ws, ps, num);
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
    delete[] ws;
    delete[] ps;


    return 0;
}

