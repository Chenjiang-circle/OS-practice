//
// Created by 陈江超 on 2020/11/21.
//

#ifndef ATTEMPER_ALGORITHM_BASE_H
#define ATTEMPER_ALGORITHM_BASE_H

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

typedef struct Job
{
    char *job_name; // 作业名
    int come_time; // 作业到达时间
    int serve_time; // 作业服务时间
} Job;

#endif //ATTEMPER_ALGORITHM_BASE_H
