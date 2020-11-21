//
// Created by 陈江超 on 2020/11/21.
//

#ifndef ATTEMPER_ALGORITHM_FCFS_H
#define ATTEMPER_ALGORITHM_FCFS_H

#include "BASE.h"

/**
 * 先来先服务算法
 * @param jobs 作业栈
 * @param file_out_name 作业调度结果的输出流
 * @return 成功返回1；否则返回0
 */
int FCFS_Algorithm(queue<Job> jobs, char* file_out_name);

#endif //ATTEMPER_ALGORITHM_FCFS_H
