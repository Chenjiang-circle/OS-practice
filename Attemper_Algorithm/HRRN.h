#ifndef ATTEMPER_ALGORITHM_HRRN_H
#define ATTEMPER_ALGORITHM_HRRN_H

#include "BASE.h"

/**
 * 计算某个作业的响应比
 * @param job 未完成的作业
 * @param now_time 现在时间
 * @return 响应比
 */
float computer_response_ratio(Job job, int now_time);

/**
 * 寻找当前最高响应比的作业
 * @param jobs 调度作业向量
 * @param now_time 现在时间
 * @return 最高响应比作业的索引
 */
int find_HRR_job(vector<Job> jobs, int now_time);

/**
 * 高响应比优先调度算法
 * @param jobs 按作业到达时间排好序的作业向量
 * @param file_name 最终作业调度结果输出流
 * @return 成功执行返回1；否则返回0
 */
int HRRN_Algorithm(vector<Job> jobs, char *file_name);

#endif //ATTEMPER_ALGORITHM_HRRN_H
