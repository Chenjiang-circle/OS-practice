#include "Job.h"

string Job::getJobName() {
    return jobName;
}

int Job::getComeTime() {
    return comeTime;
}

int Job::getServeTime() {
    return serveTime;
}

int Job::getStartTime() {
    return startTime;
}

int Job::getOverTime() {
    return overTime;
}

int Job::getRemainTime() {
    return remainTime;
}

int Job::getDeadline() {
    return deadline;
}

int Job::getLatestStartTime() {
    return latestStartTime;
}

bool Job::getOver() {
    return over;
}

void Job::setComeTime(int comeTime) {
    this->comeTime = comeTime;
}

void Job::setServeTime(int serveTime) {
    this->serveTime = serveTime;
}

void Job::setStartTime(int startTime) {
    this->startTime = startTime;
}

void Job::setOverTime(int overTime) {
    this->overTime = overTime;
}

void Job::setRemainTime(int remainTime) {
    this->remainTime = remainTime;
}

void Job::setDeadline(int deadline) {
    this->deadline = deadline;
}

void Job::setLatestStartTime(int latestStartTime) {
    this->latestStartTime = latestStartTime;
}

void Job::setOver(bool over) {
    this->over = over;
}

int Job::getPriority() {
    return priority;
}

void Job::setPriority(int priority) {
    this->priority = priority;
}

Job::Job() {
    jobName = ""; // 作业的名称
    comeTime = 0; // 作业到达时间
    serveTime = 0; // 作业服务时间
    startTime = -1; // 作业开始时间
    overTime = -1; // 作业结束时间
    remainTime = 0; // 作业剩余时间
    deadline = -1; // 作业截至时间
    latestStartTime = -1; // 最晚开始时间
    priority = -1; // 优先级
    over = false;
}

Job::Job(string line) {
    vector<string> strings;
    strings = stringToken(line, " ");
    jobName = strings[0];
    comeTime = atoi(strings[1].c_str());
    serveTime = atoi(strings[2].c_str());
    remainTime = serveTime;
    if (strings.size() == 4)
    {
        priority = atoi(strings[3].c_str());
    }
    startTime = -1;
    overTime = -1;
    deadline = -1;
    latestStartTime = -1;
    over = false;
}

Job::Job(string line, int select) {
    vector<string> strings;
    strings = stringToken(line, " ");
    // 如果选择1，表示读取的是EDF算法测试文档
    if (select == 1)
    {
        jobName = strings[0];
        comeTime = atoi(strings[1].c_str());
        serveTime = atoi(strings[2].c_str());
        latestStartTime = atoi(strings[3].c_str());
        deadline = atoi(strings[4].c_str());
        remainTime = serveTime;
        startTime = -1;
        overTime = -1;
        priority = -1;
        over = false;
    }
    // 如果选择2，表示读取的是LLF算法的测试文档
    if (select == 2)
    {
        jobName = strings[0];
        comeTime = atoi(strings[1].c_str());
        serveTime = atoi(strings[2].c_str());
        deadline = atoi(strings[3].c_str());
        startTime = -1;
        overTime = -1;
        remainTime = serveTime;
        latestStartTime = -1;
        priority = -1;
        over = false;
    }
}

