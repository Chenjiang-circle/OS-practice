#ifndef ATTEMPER_ALGORITHM_SJF_H
#define ATTEMPER_ALGORITHM_SJF_H

#include "BASE.h"
#include "SortJobs.h"

/**
 * 找到最短的未完成的作业
 * @param jobs 作业向量
 * @param now_time 现在时间
 * @return 最短的未完成作业的位置（从0开始算）
 */
int find_short_job(vector<Job> jobs, int now_time);

/**
 * 短作业优先算法
 * @param jobs 按照作业到达时间进行排序之后的向量
 * @param output_file 结果输出文件
 * @return 成功返回1；否则返回0
 */
int SJF_Algorithm(vector<Job> jobs, char* file_name);


#endif //ATTEMPER_ALGORITHM_SJF_H
