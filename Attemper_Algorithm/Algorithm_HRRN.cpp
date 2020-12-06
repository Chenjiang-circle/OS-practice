#include "Algorithm.h"

/**
 * 计算某个作业的响应比
 * @param job 未完成的作业
 * @param now_time 现在时间
 * @return 响应比
 */
float computer_response_ratio(Job job, int now_time)
{
    int wait_time = now_time - job.getComeTime();
    return (wait_time + job.getServeTime() + 0.0) / job.getServeTime();
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
    for (it = jobs.begin(); it != jobs.end(); it++)
    {
        if (!it->getOver() && it->getComeTime() <= now_time)
        {
            int hrr_tmp = computer_response_ratio(jobs[index], now_time);
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

bool Algorithm::HRRNAlgorithm(vector<Job> jobs, string fileName) {
    // 打开要读入的文件
    ofstream output_file;
    output_file.open(fileName);
    // 判断文件是否打开
    if (!output_file.is_open())
    {
        cout << "ERROR: can not open " << fileName << "!" << endl;
        return false;
    }
    output_file << "作业 到达时间 服务时间 开始时间 结束时间 周转时间 加权周转时间" << endl;

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
        end_time += job.getServeTime();
        all_time = end_time - job.getComeTime();
        weighted_all_time = (all_time + 0.0) / job.getServeTime();
        jobs[index].setOver(true);
        output_file << job.getJobName() << "\t\t" << job.getComeTime() << "\t\t" << job.getServeTime() << "\t\t" << begin_time << "\t\t" << end_time << "\t\t" << all_time << "\t\t" << weighted_all_time << endl;
        now += job.getServeTime();
        index = find_HRR_job(jobs, now);
    }
    output_file.close();
    return true;
}