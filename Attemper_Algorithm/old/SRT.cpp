#include "SRT.h"

/**
 * 在所用未完成且已经到达的作业中，选出服务时间最短的作业的索引
 * @param jobs 所有的作业
 * @param now_time 现在时间
 * @return 作业索引
 */
int find_shortest_remain_time_job(vector<Job> jobs, int now_time)
{
    int index = 0;
    int shortest_index = -1;
    int shortest_remain_time = MAX;
    vector<Job>::iterator it;
    for (it = jobs.begin();  it != jobs.end(); it++)
    {
        if (!it->over && it->come_time <= now_time)
        {
            if (it->remain_time < shortest_remain_time)
            {
                shortest_remain_time = it->remain_time;
                shortest_index = index;
            }
        }
        index++;
    }
    return shortest_index;
}

/**
 * 最短剩余时间调度算法
 * @param jobs 按作业开始时间排序的作业向量
 * @param file_name 作业调度结果输出流
 * @return 成功执行返回1；否则返回0
 */
int SRT_Algorithm(vector<Job> jobs, char* file_name)
{
    // 打开输出文件
    ofstream output_file;
    output_file.open(file_name);
    // 判断文件是否打开
    if (!output_file.is_open())
    {
        cout << "ERROR: can not open " << file_name << "!" << endl;
        return 0;
    }
    output_file << "作业\t到达时间\t服务时间\t开始时间\t结束时间\t周转时间\t加权周转时间" << endl;

    // SRT算法
    vector<Job>::iterator it;
    for (it = jobs.begin(); it != jobs.end(); it++)
    {
        it->remain_time = it->serve_time;
    }
    int now = 0; // 现在时间
    int all_time = 0;
    int weighted_all_time = 0;
    Job job;
    int index = find_shortest_remain_time_job(jobs, now);
    while (index != -1)
    {
        job = jobs[index];
        if (jobs[index].start_time == -1)
            jobs[index].start_time = now;
        now++;
        jobs[index].remain_time -= 1;
        // 判断作业是否完成
        if (jobs[index].remain_time == 0)
        {
            jobs[index].over = true;
            all_time = now - jobs[index].come_time;
            weighted_all_time = (all_time + 0.0) / job.serve_time;
            output_file << job.job_name << "\t\t" << job.come_time << "\t\t" << job.serve_time << "\t\t" << jobs[index].start_time << "\t\t" << now << "\t\t" << all_time << "\t\t" << weighted_all_time << endl;
        }
        index = find_shortest_remain_time_job(jobs, now);
    }
    output_file.close();
    return 1;
}