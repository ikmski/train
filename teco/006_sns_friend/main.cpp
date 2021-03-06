#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string>

int countFriends(int** const data, const int num)
{
    int result = 0;

    int* isChecked = new int[num];

    for (int i = 0; i < num; ++i) {
        int count = 0;

        for (int j = 0; j < num; ++j) {
            isChecked[j] = 0;
        }
        isChecked[i] = 1;

        for (int j = 0; j < num; ++j) {
            if (1 == data[i][j]) {
                if (0 == isChecked[j]) {
                    ++count;
                    isChecked[j] = 1;
                }

                int iTmp = j;
                for (int jTmp = 0; jTmp < num; ++jTmp) {
                    if (1 == data[iTmp][jTmp] && 0 == isChecked[jTmp]) {
                        ++count;
                        isChecked[jTmp] = 1;
                    }
                }

            }
        }

        if (count > result) {
            result = count;
        }
    }

    delete[] isChecked;

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
    char buf[BUFSIZ];
    while (fgets(buf, BUFSIZ, infp)) {
        ++num;
    }
    rewind(infp);
    printf("num = %d\n", num);

    // 領域確保
    int** data = new int*[num];
    for (int i = 0; i < num; ++i) {
        data[i] = new int[num];
    }

    // ファイル入力
    char* c = new char[num];
    for (int i = 0; i < num; ++i) {
        fscanf(infp, "%s", c);
        for (int j = 0; j < num; ++j) {
            if ('Y' == c[j]) {
                data[i][j] = 1;
            }
            else {
                data[i][j] = 0;
            }
printf("%d ", data[i][j]);
        }
printf("\n");
    }
    fclose(infp); // 入力ファイル

    timeval startTime;     // 開始時刻
    timeval endTime;       // 終了時刻

    // 時間計測開始
    gettimeofday(&startTime, NULL);

    int result =  countFriends(data, num);
printf("result = %d\n", result);

    // 時間計測終了
    gettimeofday(&endTime, NULL);
    double timeDiff = static_cast<double>(endTime.tv_sec  - startTime.tv_sec);
    double usecDiff = static_cast<double>(endTime.tv_usec - startTime.tv_usec);
    timeDiff += (usecDiff/1000000.0);

    // 出力ファイル
    std::string inputPath(inputFileName);
    int l = inputPath.length();
    std::string outputFileName(inputPath.substr(l-7));
    std::string indexStr(inputPath.substr(l-2));

    outfp = fopen(outputFileName.c_str(), "w");
    if (!outfp) {
        printf("file not open.");
        return -1;
    }

    fprintf(outfp, "Case #%s: %4d  %.3f[msec]\n", indexStr.c_str(), result, timeDiff*1000.0);
    fclose(outfp); // 出力ファイル

    // 解放
    for (int i = 0; i < num; ++i) {
        delete[] data[i];
    }
    delete[] data;


    return 0;
}

