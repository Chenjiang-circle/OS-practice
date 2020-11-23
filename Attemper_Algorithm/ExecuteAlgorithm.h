//
// Created by 陈江超 on 2020/11/23.
//

#ifndef ATTEMPER_ALGORITHM_EXECUTEALGORITHM_H
#define ATTEMPER_ALGORITHM_EXECUTEALGORITHM_H

#include "FCFS.h"
#include "HRRN.h"
#include "SJF.h"
#include "SRT.h"

/**
 * 根据参数执行相应的算法
 * @param jobs 作业向量
 * @param select 用户输入的参数
 * @param output_file 用户指定的文件输出路径
 */
int execute_algorithm(vector<Job> jobs, int select, char* output_file);

#endif //ATTEMPER_ALGORITHM_EXECUTEALGORITHM_H
