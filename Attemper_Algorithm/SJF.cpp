//
// Created by 陈江超 on 2020/11/22.
//

#include "SJF.h"

/**
 * 找到最短的未完成的作业
 * @param jobs 作业向量
 * @param now_time 现在时间
 * @return 最短的未完成作业的位置（从0开始算）
 */
int find_short_job(vector<Job> jobs, int now_time)
{
    int shortest_serve_time = MAX;
    int index = 0;
    int shortest_job_index = -1;
    vector<Job>::iterator it;
    for (it = jobs.begin(); it != jobs.end(); it++)
    {
        if (it->serve_time < shortest_serve_time && !it->over && it->come_time <= now_time)
        {
            shortest_serve_time = it->serve_time;
            shortest_job_index = index;
        }
        index++;
    }
    return shortest_job_index;
}

/**
 * 短作业优先算法
 * @param jobs 按照作业到达时间进行排序之后的向量
 * @param output_file 结果输出文件
 * @return 成功返回1；否则返回0
 */
int SJF_Algorithm(vector<Job> jobs, char* file_name)
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

    // SJF算法
    int now = 0; // 当前时间
    int begin_time = 0; // 开始时间
    int end_time = 0; // 结束时间
    int all_time = 0; // 周转时间
    float weighted_all_time = 0.0; // 加权周转时间
    int index = find_short_job(jobs, now);
    Job job_tmp;
    while (index != -1)
    {
        job_tmp = jobs[index];
        begin_time = end_time;
        end_time += job_tmp.serve_time;
        jobs[index].over = true;
        all_time = end_time - job_tmp.come_time;
        weighted_all_time = (all_time + 0.0) / job_tmp.serve_time;
        output_file << job_tmp.job_name << "\t\t" << job_tmp.come_time << "\t\t" << job_tmp.serve_time << "\t\t" << begin_time << "\t\t" << end_time << "\t\t" << all_time << "\t\t" << weighted_all_time << endl;
        now += job_tmp.serve_time;
        index = find_short_job(jobs, now);
    }
    output_file.close();
    return 1;
}