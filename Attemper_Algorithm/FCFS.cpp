//
// Created by 陈江超 on 2020/11/21.
//

#include "FCFS.h"

/**
 * 先来先服务算法
 * @param jobs 作业栈
 * @param file_out_name 作业调度结果的输出流
 * @return 成功返回1；否则返回0
 */
int FCFS_Algorithm(queue<Job> jobs, char* file_out_name)
{
    Job job;
    int begin_time = 0; // 作业开始时间
    int end_time = 0; // 作业完成时间
    int all_time = 0; // 作业周转时间
    float weight_all_time = 0; // 作业的加权周转时间
    // 打开要读入的文件
    ofstream output_file;
    output_file.open(file_out_name);
    // 判断文件是否打开
    if (!output_file.is_open())
    {
        cout << "ERROR: can not open " << file_out_name << "!" << endl;
        return 0;
    }
    output_file << "作业\t到达时间\t服务时间\t开始时间\t结束时间\t周转时间\t加权周转时间" << endl;
    // 按顺序从队列的头部取出作业
    while (!jobs.empty())
    {
        job = jobs.front();
        begin_time = end_time;
        end_time += job.serve_time;
        all_time = end_time - job.come_time;
        weight_all_time = (all_time+0.0) / job.serve_time;
        output_file << job.job_name << "\t\t" << job.come_time << "\t\t" << job.serve_time << "\t\t" << begin_time <<"\t\t" << end_time << "\t\t" << all_time << "\t\t" << weight_all_time << endl;
        jobs.pop();
    }
    output_file.close();
    return 1;
}
