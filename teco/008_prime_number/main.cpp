#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool isPrimeNumber(const int x)
{
    bool result = true;

    if (x < 2) {
        result = false;
    }
    for (int i = 2; i < x; ++i) {
        if (0 == x%i) {
            result = false;
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    if (2 != argc) {
        printf("arg[1] = inputFileName\n");
        return -1;
    }

    // 入力ファイル
    char* inputFileName = argv[1];
    std::ifstream ifs(inputFileName);
    if (ifs.fail()) {
        std::cout << "file not open." << std::endl;
        return -1;
    }

    // 出力ファイル
    std::ofstream ofs("./output");
    if (ofs.fail()) {
        std::cout << "file not open." << std::endl;
        return -1;
    }

    timeval startTime;     // 開始時刻
    timeval endTime;       // 終了時刻

    std::string strBuf;
    int index = 0;

    getline(ifs, strBuf);   // 先頭行を読み飛ばす

    while (getline(ifs, strBuf)) {
        std::istringstream iss(strBuf);
        std::string token;
        std::vector<int> data;
        ++index;
        while (getline(iss, token, ',')) {
            data.push_back(atoi(token.c_str()));
        }

        ofs << "Case #" << index << ": ";

        // 時間計測開始
        gettimeofday(&startTime, NULL);

        int num =  data.size();
        for (int i = 0; i < num; ++i) {
            if (isPrimeNumber(data[i])) {
                ofs << data[i] << " ";
            }
        }

        // 時間計測終了
        gettimeofday(&endTime, NULL);
        double timeDiff = static_cast<double>(endTime.tv_sec  - startTime.tv_sec);
        double usecDiff = static_cast<double>(endTime.tv_usec - startTime.tv_usec);
        timeDiff += (usecDiff/1000000.0);

        ofs << "  " << timeDiff*1000.0 << " [msec]"  << std::endl;
    }

    return 0;
}
