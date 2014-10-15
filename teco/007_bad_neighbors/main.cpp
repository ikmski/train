#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int maxDonations(std::vector<int> donations)
{
    int result = 0;
    int size = donations.size();
    int* buf = new int[size];

    // 配列の先頭から始める
    int max = 0;
    for (int i = 0; i < size-1; ++i) {
        if      (0 == i) buf[i] = donations[i];
        else if (1 == i) buf[i] = donations[i];
        else if (2 == i) buf[i] = donations[i] + buf[i-2];
        else             buf[i] = donations[i] + std::max(buf[i-2], buf[i-3]);
        max = buf[i];
        //std::cout << donations[i] << ", " << buf[i] << std::endl;
    }
    result = max;

    // 配列の2番目から始める
    max = 0;
    for (int i = 1; i < size; ++i) {
        buf[0] = 0;
        if      (1 == i) buf[i] = donations[i];
        else if (2 == i) buf[i] = donations[i] + buf[i-2];
        else             buf[i] = donations[i] + std::max(buf[i-2], buf[i-3]);
        max = buf[i];
        //std::cout << donations[i] << ", " << buf[i] << std::endl;
    }
    result = std::max(result, max);

    delete[] buf;
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

        // 時間計測開始
        gettimeofday(&startTime, NULL);

        int result =  maxDonations(data);

        // 時間計測終了
        gettimeofday(&endTime, NULL);
        double timeDiff = static_cast<double>(endTime.tv_sec  - startTime.tv_sec);
        double usecDiff = static_cast<double>(endTime.tv_usec - startTime.tv_usec);
        timeDiff += (usecDiff/1000000.0);

        ofs << "Case #" << index << ": " << result << " " << timeDiff*1000.0 << " [msec]"  << std::endl;
    }

    return 0;
}
