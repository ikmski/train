#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string>

class RouteSearch
{
private:
    int X;
    int Y;
    int** data;
    int** buf;

public:

    RouteSearch(int** a_data, int a_X, int a_Y)
    {
        data = a_data;
        X = a_X;
        Y = a_Y;

        buf = new int*[X+1];
        for (int i = 0; i <= X; ++i) {
            buf[i] = new int[Y+1];
        }

        init();
    }

    ~RouteSearch()
    {
        for (int i = 0; i <= X; ++i) {
            delete[] buf[i];
        }
        delete[] buf;
    }

    void init()
    {
        for (int i = 0; i <= X; ++i) {
            for (int j = 0; j <= Y; ++j) {
                buf[i][j] = 0;
            }
        }
    }

    int calc() { return memo(0, 0); }

private:

    int memo(int x, int y)
    {
        if ((x > X) || (y > Y)) return 0;
        if (data[x][y] == 0) return 0;
        if ((x == X) && (y == Y)) return 1;
        if (buf[x][y] > 0) return buf[x][y];
        return buf[x][y] = memo(x + 1, y) + memo(x, y + 1);
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

    // 入力
    // X, Y
    int maxX = 0;
    int maxY = 0;
    fscanf(infp, "%d,%d", &maxX, &maxY);
    printf("(X, Y) = (%d, %d)\n", maxX, maxY);

    // 領域確保
    int** data = new int*[maxX+1];
    for (int i = 0; i <= maxX; ++i) {
        data[i] = new int[maxY+1];
    }

    // 初期化
    for (int i = 0; i <= maxX; ++i) {
        for (int j = 0; j <= maxY; ++j) {
            data[i][j] = 1;
        }
    }

    // Num of Blocked
    int numOfBlocked = 0;
    fscanf(infp, "%d", &numOfBlocked);
    printf("numOfBlocked = %d\n", numOfBlocked);

    // Blocked point
    for (int i = 0; i < numOfBlocked; ++i) {
        int tmpX = 0;
        int tmpY = 0;
        fscanf(infp, "%d,%d", &tmpX, &tmpY);
        data[tmpX][tmpY] = 0;
    }
    fclose(infp); // 入力ファイル

    for (int i = 0; i <= maxX; ++i) {
        for (int j = 0; j <= maxY; ++j) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    RouteSearch* routeSearch = new RouteSearch(data, maxX, maxY);

    timeval startTime;     // 開始時刻
    timeval endTime;       // 終了時刻

    // 時間計測開始
    gettimeofday(&startTime, NULL);

    int result =  routeSearch->calc();
//printf("result = %d\n", result);

    // 時間計測終了
    gettimeofday(&endTime, NULL);
    double timeDiff = static_cast<double>(endTime.tv_sec  - startTime.tv_sec);
    double usecDiff = static_cast<double>(endTime.tv_usec - startTime.tv_usec);
    timeDiff += (usecDiff/1000000.0);

    delete routeSearch;

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
    for (int i = 0; i <= maxX; ++i) {
        delete[] data[i];
    }
    delete[] data;


    return 0;
}

