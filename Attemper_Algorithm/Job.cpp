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

Job::Job(string line) {
    vector<string> strings;
    strings = stringToken(line, "");
    jobName = strings[0];
    comeTime = atoi(strings[1].c_str());
    serveTime = atoi(strings[2].c_str());
    remainTime = serveTime;
    over = false;
}

