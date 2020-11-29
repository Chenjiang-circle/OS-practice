#ifndef ATTEMPER_ALGORITHM_JOB_H
#define ATTEMPER_ALGORITHM_JOB_H

#include "BASE.h"
#include "Utils.h"

class Job {
private:
    string jobName; // 作业的名称
    int comeTime; // 作业到达时间
    int serveTime; // 作业服务时间
    int startTime; // 作业开始时间
    int overTime; // 作业结束时间
    int remainTime; // 作业剩余时间
    int deadline; // 作业截至时间
    int latestStartTime; // 最晚开始时间
    bool over = false; // 作业是否完成
public:
    Job(string line);
    string getJobName();
    int getComeTime();
    int getServeTime();
    int getStartTime();
    int getOverTime();
    int getRemainTime();
    int getDeadline();
    int getLatestStartTime();
    bool getOver();

    void setComeTime(int comeTime);
    void setServeTime(int serveTime);
    void setStartTime(int startTime);
    void setOverTime(int overTime);
    void setRemainTime(int remainTime);
    void setDeadline(int deadline);
    void setLatestStartTime(int latestStartTime);
    void setOver(bool over);
};


#endif //ATTEMPER_ALGORITHM_JOB_H
