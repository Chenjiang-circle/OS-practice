//
// Created by 陈江超 on 2020/11/22.
//

#ifndef ATTEMPER_ALGORITHM_SORTJOBS_H
#define ATTEMPER_ALGORITHM_SORTJOBS_H

#include "BASE.h"

/**
 * 按照作业到达时间对两个作业进行比较
 * @param a 作业A
 * @param b 作业B
 * @return 比较结果
 */
bool compare_jobs_by_come_time(Job a, Job b);

/**
 * 按照作业服务时间对两个作业进行比较
 * @param a 作业A
 * @param b 作业B
 * @return 比较结果
 */
bool compare_jobs_by_serve_time(Job a, Job b);

/**
 * 对获取到的作业列表，按照到达时间进行排序
 * @param jobs 作业列表
 * @return 按照到达时间排序的作业队列
 */
queue<Job> sort_jobs(vector<Job> jobs);


#endif //ATTEMPER_ALGORITHM_SORTJOBS_H
