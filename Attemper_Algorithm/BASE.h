//
// Created by 陈江超 on 2020/11/21.
//

#ifndef ATTEMPER_ALGORITHM_BASE_H
#define ATTEMPER_ALGORITHM_BASE_H

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define LINE_MAX_LENGTH 1024
#define MAX 2147483647

typedef struct Job
{
    char job_name[LINE_MAX_LENGTH]; // 作业名
    int come_time; // 作业到达时间
    int serve_time; // 作业服务时间
    int start_time = -1; // 作业开始时间（用于SRT算法）
    int remain_time = 0; // 剩余作业时间（用于SRT算法）
    bool over = false; // 是否完成作业
} Job;



#endif //ATTEMPER_ALGORITHM_BASE_H
