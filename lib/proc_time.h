/**
 * @file  ProcTime.h
 * @brief 処理時間計測
 */

#ifndef _PROCTIME_H_
#define _PROCTIME_H_

#include <stdio.h>
#include <sys/time.h>
#include <time.h>

/*
 * @class ProcTime
 * @brief 処理時間計測クラス
 */
class ProcTime
{
private:
    char*   proc_name;      //!< 処理名称
    timeval start_time;     //!< 開始時刻
    timeval end_time;       //!< 終了時刻

public:
    explicit ProcTime(char* const name) : proc_name(name) {}    //!< コンストラクタ
    ProcTime() : proc_name((char*)"Proc Time") {}               //!< コンストラクタ
    ~ProcTime() {};                                             //!< デストラクタ

    /** 計測開始 */
    inline void start() { gettimeofday(&start_time, NULL); }

    /** 計測終了 */
    inline void end()
    {
        gettimeofday(&end_time, NULL);
        double time_diff = static_cast<double>(end_time.tv_sec  - start_time.tv_sec);
        double usec_diff = static_cast<double>(end_time.tv_usec - start_time.tv_usec);
        time_diff += (usec_diff/1000000.0);
        printf("%s = %.6lf [sec]\n", proc_name, time_diff);
    }
};

#endif  // _PROCTIME_H_

