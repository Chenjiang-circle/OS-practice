//
// Created by 陈江超 on 2020/11/22.
//

#include "HRRN.h"

/**
 * 计算某个作业的响应比
 * @param job 未完成的作业
 * @param now_time 现在时间
 * @return 响应比
 */
float computer_response_ratio(Job job, int now_time)
{
    int wait_time = now_time - job.come_time;
    return (wait_time + job.serve_time + 0.0) / job.serve_time;
}

/**
 * 寻找当前最高响应比的作业
 * @param jobs 调度作业向量
 * @param now_time 现在时间
 * @return 最高响应比作业的索引
 */
int find_HRR_job(vector<Job> jobs, int now_time)
{
    float hrr = -1; // 最高响应比
    int index = 0; // 当前索引
    int hrr_index = -1; // 最高响应比作业对应的索引
    vector<Job>::iterator it;
//    cout << "now_time: " << now_time << endl;
    for (it = jobs.begin(); it != jobs.end(); it++)
    {
        if (!it->over && it->come_time <= now_time)
        {
            int hrr_tmp = computer_response_ratio(jobs[index], now_time);
//            cout << jobs[index].job_name << "的响应比为：" << hrr_tmp << endl;
            if (hrr_tmp > hrr)
            {
                hrr = hrr_tmp;
                hrr_index = index;
            }
        }
        index++;
    }
    return hrr_index;
}

/**
 * 高响应比优先调度算法
 * @param jobs 按作业到达时间排好序的作业向量
 * @param file_name 最终作业调度结果输出流
 * @return 成功执行返回1；否则返回0
 */
int HRRN_Algorithm(vector<Job> jobs, char *file_name)
{
    // 打开要读入的文件
    ofstream output_file;
    output_file.open(file_name);
    // 判断文件是否打开
    if (!output_file.is_open())
    {
        cout << "ERROR: can not open " << file_name << "!" << endl;
        return 0;
    }
    output_file << "作业\t到达时间\t服务时间\t开始时间\t结束时间\t周转时间\t加权周转时间" << endl;

    // HRRN算法
    int now = 0;
    int begin_time = 0;
    int end_time = 0;
    int all_time = 0;
    float weighted_all_time = 0;
    int index = find_HRR_job(jobs, now);
    Job job;
    while (index != -1)
    {
        job = jobs[index];
        begin_time = end_time;
        end_time += job.serve_time;
        all_time = end_time - job.come_time;
        weighted_all_time = (all_time + 0.0) / job.serve_time;
        jobs[index].over = true;
        output_file << job.job_name << "\t\t" << job.come_time << "\t\t" << job.serve_time << "\t\t" << begin_time << "\t\t" << end_time << "\t\t" << all_time << "\t\t" << weighted_all_time << endl;
        now += job.serve_time;
        index = find_HRR_job(jobs, now);
    }
    output_file.close();
    return 1;
}