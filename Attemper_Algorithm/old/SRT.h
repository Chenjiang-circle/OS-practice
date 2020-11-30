#ifndef ATTEMPER_ALGORITHM_SRT_H
#define ATTEMPER_ALGORITHM_SRT_H

#include "../BASE.h"

/**
 * 在所用未完成且已经到达的作业中，选出服务时间最短的作业的索引
 * @param jobs 所有的作业
 * @param now_time 现在时间
 * @return 作业索引
 */
int find_shortest_remain_time_job(vector<Job> jobs, int now_time);

/**
 * 最短剩余时间调度算法
 * @param jobs 按作业开始时间排序的作业向量
 * @param file_name 作业调度结果输出流
 * @return 成功执行返回1；否则返回0
 */
int SRT_Algorithm(vector<Job> jobs, char* file_name);

#endif //ATTEMPER_ALGORITHM_SRT_H
