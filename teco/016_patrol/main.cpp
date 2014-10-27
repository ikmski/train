#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string>

class Patrol
{
private:
    int size;
    int end;
    int pos;
    int** data;

public:

    Patrol(int** a_data, int a_size, int a_start, int a_end)
    {
        data  = a_data;
        size  = a_size;
        pos = a_start;
        end   = a_end;
    }

    ~Patrol() {}

    bool calc()
    {
        bool result = true;

        dfs();

        int num = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                num += data[i][j];
            }
        }
        if (num > 0) result = false;

        return result;
    }

private:

    void dfs()
    {
        int sum = 0;
        for (int j = 0; j < size; ++j) {
            sum += data[pos][j];
        }
        if (sum == 0) return;

        for (int j = end+1; j < size; ++j) {
            if (data[pos][j] > 0) {
                --data[pos][j];
                --data[j][pos];
                pos = j;
                dfs();
            }
        }
        for (int j = 0; j <= end; ++j) {
            if (data[pos][j] > 0) {
                --data[pos][j];
                --data[j][pos];
                pos = j;
                dfs();
            }
        }

        return;
    }

};

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
    int tmpM, tmpN;
    while (EOF != fscanf(infp, "%d %d", &tmpM, &tmpN)) {
        printf("%d %d\n", tmpM, tmpN);
        if (tmpM > num) num = tmpM;
        if (tmpN > num) num = tmpN;
    }
    rewind(infp);
    printf("num = %d\n", num);

    // 領域確保
    int** data = new int*[num];
    for (int i = 0; i < num; ++i) {
        data[i] = new int[num];
    }

    // 初期化
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            data[i][j] = 0;
        }
    }

    // 入力
    while (EOF != fscanf(infp, "%d %d", &tmpM, &tmpN)) {
        if (0 == tmpM || 0 == tmpN) continue;
        ++data[tmpM-1][tmpN-1];
        ++data[tmpN-1][tmpM-1];
    }
    fclose(infp); // 入力ファイル

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    Patrol* patrol = new Patrol(data, num, 0, 1);

    timeval startTime;     // 開始時刻
    timeval endTime;       // 終了時刻

    // 時間計測開始
    gettimeofday(&startTime, NULL);

    bool result = patrol->calc();

    // 時間計測終了
    gettimeofday(&endTime, NULL);
    double timeDiff = static_cast<double>(endTime.tv_sec  - startTime.tv_sec);
    double usecDiff = static_cast<double>(endTime.tv_usec - startTime.tv_usec);
    timeDiff += (usecDiff/1000000.0);

    delete patrol;

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

    std::string resultStr = "NG";
    if (result) {
        resultStr = "OK";
    }
    fprintf(outfp, "Case #%s: %s  %.3f[msec]\n", indexStr.c_str(), resultStr.c_str(), timeDiff*1000.0);
    printf("Case #%s: %s  %.3f[msec]\n", indexStr.c_str(), resultStr.c_str(), timeDiff*1000.0);

    // 解放
    for (int i = 0; i < num; ++i) {
        delete[] data[i];
    }
    delete[] data;


    return 0;
}

